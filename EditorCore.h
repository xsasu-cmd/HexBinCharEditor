#ifndef EDITORCORE_H
#define EDITORCORE_H

#include <vector> // For buffer storage
#include <optional> // For optional byte value
#include <string> // For file handling
#include <iostream> // For error handling

class EditorCore { // Class to handle the core functionality of the editor

public:
    void loadBuffer(const std::vector<unsigned char>& data);  // Load data into the buffer
    const std::vector<unsigned char>& getBuffer() const; // Get the buffer
    bool editByte(size_t offset, unsigned char newValue); // Edit a byte in the buffer
    bool isLoaded() const; // Check if the buffer is loaded

private:
    std::vector<unsigned char> buffer; // Buffer to store file data
};

#endif
