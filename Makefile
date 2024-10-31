# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

# Additional linker flags
LDFLAGS = -fPIC -no-pie
GTEST_DIR = /usr/local
GTEST_INCLUDES = -isystem $(GTEST_DIR)/include
GTEST_LIBS = -L$(GTEST_DIR)/lib -lgtest -lgtest_main -pthread 

# Source files for the main application
SOURCES = Builder.cpp Building.cpp CommercialBuilding.cpp CommercialBuildingBuilder.cpp \
          Director.cpp IndustrialBuilding.cpp IndustrialBuildingBuilder.cpp LandmarkBuilding.cpp \
          LandmarkBuildingBuilder.cpp ResidentialBuilding.cpp ResidentialBuildingBuilder.cpp Sensor.cpp 

# Source files for unit tests
TEST_SOURCES = Main.cpp  # Add your test source files here

# Object files for the main application
OBJECTS = $(SOURCES:.cpp=.o)

# Object files for unit tests
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

# Executable names
EXECUTABLE = smart_home
TEST_EXECUTABLE = runSmartHomeTests

# Default target (builds the main executable)
all: $(EXECUTABLE)

# Linking rule for the main executable
$(EXECUTABLE): $(OBJECTS) TestingMain.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) TestingMain.o -o $@

# Linking rule for the unit test executable
$(TEST_EXECUTABLE): $(OBJECTS) $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) $(TEST_OBJECTS) $(GTEST_LIBS) -o $@

# Compilation rule for individual object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(TEST_OBJECTS) $(TEST_EXECUTABLE)

# Phony targets
.PHONY: all clean run debug valgrind test

# Run rule for the main application
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Debug rule
debug: CXXFLAGS += -g
debug: clean all

# Valgrind rule
valgrind: $(EXECUTABLE)
	valgrind --leak-check=full --track-origins=yes --undef-value-errors=yes ./$(EXECUTABLE)

# Test rule
test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)
