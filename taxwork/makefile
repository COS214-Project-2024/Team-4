# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -g
LDFLAGS = 
VALGRIND = valgrind --leak-check=full --track-origins=yes --show-reachable=yes

# Target executable
TARGET = testTaxes

# Source files
SOURCES = testTaxes.cpp CollectTaxesCommand.cpp Income.cpp Property.cpp Sales.cpp \
          SetTaxCommand.cpp TaxSatisfactionStrategy.cpp TaxSystem.cpp TaxType.cpp \
          Government.cpp CityService.cpp Policy.cpp VAT.cpp

# Header files
HEADERS = CollectTaxesCommand.h Income.h Property.h Sales.h SetTaxCommand.h \
          TaxSatisfactionStrategy.h TaxSystem.h TaxType.h Resource.h \
          ResourceAllocationStrategy.h ResourceApprovalHandler.h \
          ResourceAvailability.h ResourceManager.h ResourceType.h Government.h \
          GovObserver.h CityService.h Policy.h VAT.h

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

# Run the program
run: $(TARGET)
	./$(TARGET)

# Run the program with Valgrind for memory leak detection
valgrind: $(TARGET)
	$(VALGRIND) ./$(TARGET)

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Debugging target (recompile with debug symbols)
debug: clean all

# Additional target to ensure main is executed
main: all
q   