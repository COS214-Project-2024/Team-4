#include "Building.h"

//construtor
Building::Building(const std::string& name, float area, int floors, int capacity,
                   float satisfactionImpact, float growthImpact, float consumption)
    {
	this->name = name;
	this->area = area;
	this->floors = floors;
	this->capacity = capacity;
	this->citizenSatisfaction = satisfactionImpact;
	this->economicGrowth = growthImpact;
	this->resourceConsumption = consumption;

	}


//getters
float Building::getSatisfaction() const{
	return this->citizenSatisfaction;
}

float Building::getEconomicGrowth() const{
	return this->economicGrowth;
}

float Building::getResourceConsumption()const {
	return this->resourceConsumption;	
}

//i forgot what i needed this for
Building::Building(int Builder) {
	// TODO - implement Building::Building
	throw "Not yet implemented";
}
