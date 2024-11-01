# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -g
LDFLAGS = 
VALGRIND = valgrind --leak-check=full --track-origins=yes --show-reachable=yes

# Target executable
TARGET = main

# Source files
SOURCES = CollectTaxesCommand.cpp Income.cpp Property.cpp Sales.cpp SetTaxCommand.cpp TaxSatisfactionStrategy.cpp TaxSystem.cpp TaxType.cpp VAT.cpp

# Header files (not necessary for compilation but for dependency tracking)
HEADERS = CollectTaxesCommand.h Income.h Property.h Sales.h SetTaxCommand.h TaxSatisfactionStrategy.h TaxSystem.h TaxType.h VAT.h Resource.h ResourceAllocationStrategy.h ResourceApprovalHandler.h ResourceAvailability.h ResourceManager.h ResourceType.h

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Link the target executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

# Compile each source file into an object file
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program with Valgrind for memory leak detection
valgrind: $(TARGET)
	$(VALGRIND) ./$(TARGET)

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Debugging target (recompile with debug symbols)
debug: clean all
