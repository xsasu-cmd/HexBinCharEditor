#include "InputHandler.h"
#include <sstream> // For string stream
#include <bitset> // For bit manipulation
#include <iostream> // For error handling
#include <cctype> // For isprint
#include <iomanip> // For formatting output
#include <string> // For string handling
#include <vector> // For buffer storage
#include <algorithm> // For std::find_if
#include <optional> // For optional byte value

std::optional<unsigned char> InputHandler::parseInput(const std::string& input) const { // Takes a string and returns an optional byte value if valid
    if (input.empty()) return std::nullopt; // Check if input is empty

    // HEX input
    if (input.rfind("hex ", 0) == 0) { // Check if input starts with "hex "
        std::string value = input.substr(4); // Extract the hex value

        unsigned int byte; // Variable to store the converted value
        std::stringstream ss; // String stream for conversion
        ss << std::hex << value; // Convert hex string to unsigned int
        if (ss >> byte && byte <= 0xFF) { // Check if conversion was successful and within byte range
            return static_cast<unsigned char>(byte); // Return the byte value
        }
    }

    // BIN input
    else if (input.rfind("bin ", 0) == 0) {  // Check if input starts with "bin "
        std::string value = input.substr(4);
        if (value.length() == 8) { // Check if the length is 8
            try {
                return static_cast<unsigned char>(std::bitset<8>(value).to_ulong()); // Convert binary string to unsigned char
            } catch (...) {
                return std::nullopt;
            }
        }
    }

    // CHAR input
    else if (input.rfind("char ", 0) == 0) {  // Check if input starts with "char "
        std::string value = input.substr(5); 
        if (value.length() == 1) { // Check if the length is 1
            return static_cast<unsigned char>(value[0]); // Return the ASCII value of the character
        }
    }

    return std::nullopt; // Invalid input
}
