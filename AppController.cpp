#include "AppController.h"
#include <iostream> // For input/output operations
#include <fstream> // For file handling
#include <vector> // For buffer storage
#include <iomanip> // For formatting output
#include <bitset> // For bit manipulation
#include <cctype> // For isprint
#include <sstream> // For string stream
#include <optional> // For optional byte value
#include <string> // For file handling
#include <algorithm> // For std::find_if

std::string AppController::getFilePath() {
    std::string path;
    std::cout << "Enter path to the file: ";
    std::getline(std::cin, path);
    return path;
}

void AppController::displayMenu(const std::string& filePath) { // Display the file content in a formatted manner
    if (!fileHandler.loadFile(filePath)) { // Load the file into the buffer
        std::cerr << "Failed to load file.\n"; // Error handling
        return;
    }

    editorCore.loadBuffer(fileHandler.getBuffer()); // Load the buffer with the file data

    bool running = true; // Flag to control the main loop
    
    // Main loop to handle user input and display content
    // This loop will continue until the user enters quit
    while (running) { 
        displayRenderer.render(editorCore.getBuffer()); // Render the file content

        std::string command; // Variable to store user command
        std::cout << "\nCommands: edit <offset> <format val>, save, quit\n> "; // Display command prompt
        std::cout << "Enter command: ";

        // Get user input
        std::getline(std::cin, command); 

        // Check for quit command
        if (command == "quit") { 
            if (changesMade) {
                std::cout << "You have unsaved changes. Do you really want to quit? (y/n): ";
                std::string response;
                std::getline(std::cin, response); // Get user confirmation
                if (response != "y" && response != "Y") { // Check if user wants to quit
                    std::cout << "Quit cancelled.\n"; // If not, cancel quit
                    continue; // If not, continue the loop
                }
            }
            running = false;
        
        // Check for save command
        } else if (command == "save") { 
            if (fileHandler.saveFile(filePath, editorCore.getBuffer())) { // Save the buffer to the file
                std::cout << "File saved successfully.\n"; // Success message
                changesMade = false; // Reset changesMade flag after saving
            } else {
                std::cout << "Failed to save file.\n"; // Error handling
            }
            
        // Check for edit command
        } else if (command.rfind("edit ", 0) == 0) { // Check for edit command
            std::istringstream iss(command.substr(5)); // Extract the command parameters
            size_t offset; 
            std::string valueStr; 
            if (iss >> offset && std::getline(iss, valueStr)) { // Check if offset and value are provided
                valueStr.erase(0, valueStr.find_first_not_of(" \t")); // Remove leading whitespace
                auto val = inputHandler.parseInput(valueStr); // Parse the value
                if (val && editorCore.editByte(offset, *val)) { // Edit the byte in the buffer
                    std::cout << "Byte edited.\n";
                    changesMade = true; // Set flag to indicate changes were made 
                } else {
                    std::cout << "Invalid offset or value.\n"; // Error handling
                }
            } else {
                std::cout << "Usage: edit <offset> <hex/bin/char value>\n"; // Prompt user for correct entry
            }
        } else {
            std::cout << "Unknown command.\n"; // Error handling
        }
    }
}


void AppController::run() {
    std::string filePath = getFilePath();
    displayMenu(filePath);
}
