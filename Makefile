# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Executable name
TARGET = HEXBINCHAREditor


# Source and object files
SRCS = main.cpp AppController.cpp FileHandler.cpp DisplayRenderer.cpp InputHandler.cpp EditorCore.cpp
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target to remove object files and executable
clean:
	rm -f $(OBJS) $(TARGET)
