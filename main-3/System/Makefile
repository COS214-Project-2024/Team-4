# Makefile for compiling C++ files in a folder

# Compiler settings
CXX := g++ -g
CXXFLAGS := -std=c++17

# Source files (both .cpp and .h)
SRC := $(wildcard *.cpp)
HDR := $(wildcard *.h)

# Object files
OBJ := $(SRC:.cpp=.o)

# Output binary
TARGET := my_program

# Default target
all: $(TARGET)

# Link object files to create the binary
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile .cpp files to object files
%.o: %.cpp $(HDR)
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Clean up generated files
clean:
	rm -f $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET)

doxygen:
	doxygen dconfig

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

gdb: $(TARGET)
	gdb ./$(TARGET)