#ifndef DISPLAYRENDERER_H
#define DISPLAYRENDERER_H

#include <vector> // For std::vector


class DisplayRenderer {
public:
    void render(const std::vector<unsigned char>& buffer) const; // Function to render content
};

#endif