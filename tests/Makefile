# Makefile for compiling C++ files in a folder

# Compiler settings
CXX := g++
CXXFLAGS := -std=c++11 -Wall

# Source files (both .cpp and .h)
SRC := $(wildcard *.cpp)
HDR := $(wildcard *.h)

# Object files
OBJ := $(SRC:.cpp=.o)

# Output binary
TARGET := my_program

# Default target
all: $(TARGET)

# Compile .cpp files to object files
%.o: %.cpp $(HDR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files to create the binary
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean up generated files
clean:
	rm -f $(OBJ) $(TARGET)
