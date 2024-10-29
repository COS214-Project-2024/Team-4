#ifndef BUILDER_H
#define BUILDER_H
#include<string>
using namespace std;
#include "Building.h"

class Builder {

protected:
	string name;
	float area;
	int floors;
	int capacity;
	float citizenSatisfaction;
	float economicGrowth;
	float resourceConsumption;

public:
	Builder setName(string name);

	Builder setArea(float area);

	Builder setFloors(int floors);

	Builder setCapacity(int capacity);

	Builder setCitizenSatisfaction(float citizenSatisfaction);

	Builder setEconomicGrowth(float economicGrowth);

	Builder setResourceConsumption(float resourceConsumption);

	Building build();
};

#endif
