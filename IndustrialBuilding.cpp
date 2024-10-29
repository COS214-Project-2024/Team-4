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
	economicGrowth = productionCapacity * 0.1;
}

void IndustrialBuilding::calculateResourceConsumption() {
	resourceConsumption = productionCapacity * 0.2;
}

void IndustrialBuilding::calculateSatisfactionImpact() {
	citizenSatisfaction = productionCapacity * 0.05;
}
