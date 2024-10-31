#ifndef BUILDER_H
#define BUILDER_H
#include<string>
using namespace std;
#include "Building.h"
#include <memory>

class Builder {

protected:
	string name;
	float area = 0.0f;
    int floors = 0;
    int capacity = 0;
    float citizenSatisfaction = 0.0f;
    float economicGrowth = 0.0f;
    float resourceConsumption = 0.0f;
public:
	Builder& setName(string name);

	Builder& setArea(float area);

	Builder& setFloors(int floors);

	Builder& setCapacity(int capacity);

	Builder& setCitizenSatisfaction(float citizenSatisfaction);

	Builder& setEconomicGrowth(float economicGrowth);

	Builder& setResourceConsumption(float resourceConsumption);

	//Building build();
	virtual ~Builder() = default;

	 virtual std::unique_ptr<Building> build() = 0;
};

#endif
