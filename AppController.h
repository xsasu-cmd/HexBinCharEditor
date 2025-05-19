#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <iostream> // For input/output operations
#include "FileHandler.h" // Include the FileHandler class
#include "DisplayRenderer.h" // Include the DisplayRenderer class
#include "InputHandler.h" // Include the InputHandler class
#include "EditorCore.h" // Include the EditorCore class


class AppController {
public:
    void run(); // Main function to run the application
    // This function will handle the main logic of the application

private:
    std::string getFilePath(); // Get the file path from the user
    void displayMenu(const std::string& filePath); // Display the file content in a formatted manner
    
    FileHandler fileHandler; // Instance of FileHandler to manage file operations
    DisplayRenderer displayRenderer; // Instance of DisplayRenderer to handle rendering
    InputHandler inputHandler; // Instance of InputHandler to manage user input
    EditorCore editorCore; // Instance of EditorCore to handle core functionality
};

#endif
