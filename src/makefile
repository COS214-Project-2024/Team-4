# Compiler and flags
CC = g++
CFLAGS = -std=c++14 -Wall -g

# Source and object files
SRC_DIR = src
BUILD_DIR = build

SRCS = main.cpp Builder.cpp Building.cpp CommercialBuilding.cpp \
       CommercialBuildingBuilder.cpp Director.cpp IndustrialBuilding.cpp \
       IndustrialBuildingBuilder.cpp LandmarkBuilding.cpp \
       LandmarkBuildingBuilder.cpp ResidentialBuilding.cpp \
       ResidentialBuildingBuilder.cpp UtilityMediator.cpp \
       Utility.cpp WaterSupply.cpp WasteManagement.cpp \
       ResourceManager.cpp Resource.cpp ResourceType.cpp \
       ResourceAvailability.cpp

OBJS = $(SRCS:.cpp=.o)

# Rule to build the executable
main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main

# Rule for compiling .cpp files into .o files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Run the program
run: main
	./main

# Clean up object files and the executable
clean:
	rm -f *.o main

# Phony targets to prevent issues with files named 'clean' or 'run'
.PHONY: clean run
