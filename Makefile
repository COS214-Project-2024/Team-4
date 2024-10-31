# Define the compiler and compiler flags
CC = g++
CFLAGS = -std=c++14 -g

# Define the list of object files
ofiles = main.o Builder.o Building.o CommercialBuilding.o CommercialBuildingBuilder.o \
          Director.o IndustrialBuilding.o IndustrialBuildingBuilder.o LandmarkBuilding.o \
          LandmarkBuildingBuilder.o ResidentialBuilding.o ResidentialBuildingBuilder.o 

# Define the makefile rule to build the executable
main: $(ofiles)
	$(CC) $(CFLAGS) $(ofiles) -o main

# Define individual rules for each source file
main.o: main.cpp Builder.h Building.h CommercialBuilding.h CommercialBuildingBuilder.h \
         Director.h IndustrialBuilding.h IndustrialBuildingBuilder.h LandmarkBuilding.h \
         LandmarkBuildingBuilder.h ResidentialBuilding.h ResidentialBuildingBuilder.h
	$(CC) $(CFLAGS) -c main.cpp

Builder.o: Builder.cpp Builder.h
	$(CC) $(CFLAGS) -c Builder.cpp

Building.o: Building.cpp Building.h
	$(CC) $(CFLAGS) -c Building.cpp

CommercialBuilding.o: CommercialBuilding.cpp CommercialBuilding.h
	$(CC) $(CFLAGS) -c CommercialBuilding.cpp

CommercialBuildingBuilder.o: CommercialBuildingBuilder.cpp CommercialBuildingBuilder.h
	$(CC) $(CFLAGS) -c CommercialBuildingBuilder.cpp

Director.o: Director.cpp Director.h
	$(CC) $(CFLAGS) -c Director.cpp

IndustrialBuilding.o: IndustrialBuilding.cpp IndustrialBuilding.h
	$(CC) $(CFLAGS) -c IndustrialBuilding.cpp

IndustrialBuildingBuilder.o: IndustrialBuildingBuilder.cpp IndustrialBuildingBuilder.h
	$(CC) $(CFLAGS) -c IndustrialBuildingBuilder.cpp

LandmarkBuilding.o: LandmarkBuilding.cpp LandmarkBuilding.h
	$(CC) $(CFLAGS) -c LandmarkBuilding.cpp

LandmarkBuildingBuilder.o: LandmarkBuildingBuilder.cpp LandmarkBuildingBuilder.h
	$(CC) $(CFLAGS) -c LandmarkBuildingBuilder.cpp

ResidentialBuilding.o: ResidentialBuilding.cpp ResidentialBuilding.h
	$(CC) $(CFLAGS) -c ResidentialBuilding.cpp

ResidentialBuildingBuilder.o: ResidentialBuildingBuilder.cpp ResidentialBuildingBuilder.h
	$(CC) $(CFLAGS) -c ResidentialBuildingBuilder.cpp

# Define a rule to run the program with Valgrind
run: main
	valgrind ./main

# Define a rule to clean up object files and executable
clean: 
	rm -f *.o main

# Phony targets
.PHONY: clean run
