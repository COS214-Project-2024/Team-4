#include "LandmarkBuilding.h"

LandmarkBuilding::LandmarkBuilding(const std::string& name, float area, int floors,
                                         int capacity, float citizenSatisfaction,
                                         float economicGrowth, float resourceConsumption,
                                         int visitorCapacity, float culturalValue):Building(name, area, floors, capacity, citizenSatisfaction, economicGrowth, resourceConsumption)
										 {
	this->visitorCapacity = visitorCapacity;
	this->culturalValue = culturalValue;
	this->bType = "Landmark";
}

string LandmarkBuilding::getType()const {
	return this->bType;
}

void LandmarkBuilding::updateImpacts() {
	calculateEconomicImpact();
	calculateResourceConsumption();
	calculateSatisfactionImpact();
}

void LandmarkBuilding::hostEvent(int visitors) {
	//not sure yet
	visitorCapacity += visitors;
}

void LandmarkBuilding::calculateEconomicImpact() {
	economicGrowth += visitorCapacity * culturalValue;
}

void LandmarkBuilding::calculateResourceConsumption() {
	resourceConsumption += visitorCapacity * 0.1;
}

void LandmarkBuilding::calculateSatisfactionImpact() {
	citizenSatisfaction += visitorCapacity * 0.01;
}
