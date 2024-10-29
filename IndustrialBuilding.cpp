#include "IndustrialBuilding.h"

IndustrialBuilding::IndustrialBuilding(const std::string& name, float area, int floors, int capacity,
                        float citizenSatisfaction, float economicGrowth, float resourceConsumption,
                        float pollutionLevel, float productionCapacity):Building(name, area, floors, capacity, citizenSatisfaction, economicGrowth, resourceConsumption)
						{
	this->pollutionLevel = pollutionLevel;
	this->productionCapacity = productionCapacity;
	this->bType = "Industrial";

}

string IndustrialBuilding::getType() const{
	return this->bType;
}

void IndustrialBuilding::updateImpacts() {
	calculateEconomicImpact();
	calculateResourceConsumption();
	calculateSatisfactionImpact();
}

void IndustrialBuilding::upgradeTech(float techLevel) {
	productionCapacity += techLevel; //maybe change this ,find better logic
}

void IndustrialBuilding::calculateEconomicImpact() {
	economicGrowth = productionCapacity * 0.3f;
}

void IndustrialBuilding::calculateResourceConsumption() {
	resourceConsumption = productionCapacity * 0.2f;
}

void IndustrialBuilding::calculateSatisfactionImpact() {
	//citizenSatisfaction = productionCapacity * 0.05;
	citizenSatisfaction = -pollutionLevel * 0.1f;
}

void IndustrialBuilding::construct() {
	   std::cout << "Constructing Industrial Building: " << name << std::endl;
    std::cout << "Area: " << area << ", Floors: " << floors << ", Capacity: " << capacity << std::endl;
    std::cout << "Production Capacity: " << productionCapacity << ", Pollution Level: " << pollutionLevel << std::endl;
    std::cout << "Industrial Building constructed successfully!" << std::endl;

}
