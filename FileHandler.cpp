#include "FileHandler.h" // INclude the class declaration
#include <fstream> // For file handling
#include <iostream> // For error handling
#include <vector> // For buffer storage
#include <iomanip> // For formatting output
#include <bitset> // For bit manipulation
#include <string> // For string handling
#include <sstream> // For string stream
#include <algorithm> // For std::find_if
#include <cctype> // For isprint

bool FileHandler::loadFile(const std::string& path) { // Load a file into the buffer
    std::ifstream file(path, std::ios::binary); // Open the file in binary mode
    if (!file) {// Check if the file opened successfully
        std::cerr << "Error: Unable to open file: " << path << std::endl;// Error handling
        return false; // Return false if the file could not be opened
    }

    buffer = std::vector<unsigned char>( // Read the file into the buffer
        std::istreambuf_iterator<char>(file), // Read from the file
        std::istreambuf_iterator<char>() // End of file iterator
    );

    return true; // Return true if the file was loaded successfully
}

const std::vector<unsigned char>& FileHandler::getBuffer() const { // Get the buffer    
    return buffer;  // Return the buffer
}
// Save the buffer to a file
bool FileHandler::saveFile(const std::string& path, const std::vector<unsigned char>& buffer) {  
    std::ofstream file(path, std::ios::binary); // Open the file in binary mode
    if (!file) { // Check if the file opened successfully
        std::cerr << "Error: Could not open file for writing: " << path << std::endl; // Error handling
        return false;
    }

    file.write(reinterpret_cast<const char*>(buffer.data()), buffer.size()); // Write the buffer to the file
    if (!file) { // Check if the write operation was successful
        std::cerr << "Error: Failed to write to file: " << path << std::endl; // Error handling
        return false;
    }

    return true;
}
