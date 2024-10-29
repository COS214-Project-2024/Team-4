#include "LandmarkBuilding.h"

LandmarkBuilding::LandmarkBuilding(const std::string& name, float area, int floors, int capacity,
                                   float citizenSatisfactionImpact, float economicGrowthImpact,
                                   float resourceConsumption, int visitorCapacity, float culturalValue, bool isHistoric)
 :Building(name, area, floors, capacity, citizenSatisfaction, economicGrowth, resourceConsumption)
										 {
	this->visitorCapacity = visitorCapacity;
	this->culturalValue = culturalValue;
	this->isHistoric = false;
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
	 culturalValue += 5.0f;
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
void LandmarkBuilding::construct() {
	std::cout << "Constructing Landmark Building: " << name << std::endl;
    std::cout << "Area: " << area << ", Floors: " << floors << ", Capacity: " << capacity << std::endl;
    std::cout << "Visitor Capacity: " << visitorCapacity << ", Cultural Value: " << culturalValue
              << ", Historic: " << (isHistoric ? "Yes" : "No") << std::endl;
    std::cout << "Landmark Building constructed successfully!" << std::endl;

}
