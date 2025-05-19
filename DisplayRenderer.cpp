#include "DisplayRenderer.h" // Include the class declaration
#include <iostream>
#include <iomanip>
#include <bitset>
#include <cctype>
#include <vector>

void DisplayRenderer::render(const std::vector<unsigned char>& buffer) const { // Render the file content in a formatted manner
    if (buffer.empty()) { // Check if the buffer is empty
        std::cout << "File is empty.\n"; // Error handling
        return; // Return if the buffer is empty
    }

    std::cout << "File Content:\n"; // Display header
    std::cout << "Offset\tHex\t\tBin\t\t\tChar\n";
    std::cout << "-----------------------------------------------------------\n";

    for (size_t i = 0; i < buffer.size(); ++i) {
        unsigned char byte = buffer[i];
        std::cout << std::setw(4) << std::setfill('0') << std::hex << i
                  << "\t" << std::setw(2) << std::hex << (int)byte
                  << "\t\t" << std::bitset<8>(byte)
                  << "\t\t" << (isprint(byte) ? (char)byte : '.')
                  << "\n";
    }
}
