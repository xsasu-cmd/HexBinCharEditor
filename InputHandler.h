#ifndef INPUTHANDLER_H 
#define INPUTHANDLER_H

#include <string>
#include <optional> 

class InputHandler { // Class to handle user input
public:
    // Takes a string and returns an optional byte value if valid
    std::optional<unsigned char> parseInput(const std::string& input) const;
};

#endif
