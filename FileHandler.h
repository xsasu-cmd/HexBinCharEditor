#ifndef FILEHANDLER_H 
#define FILEHANDLER_H

#include <string> // For file handling
#include <vector> // For buffer storage
#include <fstream> // For file handling
#include <iostream> // For error handling
#include <iomanip> // For formatting output
#include <bitset> // For bit manipulation
#include <string> // For string handling

class FileHandler {
public:
    bool loadFile(const std::string& path); // Load a file into the buffer
    const std::vector<unsigned char>& getBuffer() const;  // Get the buffer
    bool saveFile(const std::string& path, const std::vector<unsigned char>& buffer); // Save the buffer to a file

private:
    std::vector<unsigned char> buffer; // Buffer to store file data
};

#endif 