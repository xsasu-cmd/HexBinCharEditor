#include "EditorCore.h"

#include <vector> // For buffer storage
#include <optional> // For optional byte value
#include <iostream> // For error handling

void EditorCore::loadBuffer(const std::vector<unsigned char>& data) { // Load data into the buffer
    buffer = data; // Store the data in the buffer
}

const std::vector<unsigned char>& EditorCore::getBuffer() const { // Get the buffer
    return buffer; 
}

bool EditorCore::editByte(size_t offset, unsigned char newValue) { // Edit a byte in the buffer
    if (offset >= buffer.size()) { // Check if the offset is within bounds
        return false; // Out of bounds
    }
    buffer[offset] = newValue; // Update the byte at the specified offset
    return true;
}

bool EditorCore::isLoaded() const { // Check if the buffer is loaded
    return !buffer.empty(); // Check if the buffer is not empty
}
