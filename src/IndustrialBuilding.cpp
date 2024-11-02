#include "IndustrialBuilding.h"

//constructor
IndustrialBuilding::IndustrialBuilding(const std::string& name, float area, int floors, int capacity,
                        float citizenSatisfaction, float economicGrowth, float resourceConsumption,
                        float pollutionLevel, float productionCapacity):Building(name, area, floors, capacity, citizenSatisfaction, economicGrowth, resourceConsumption)
						{
	this->pollutionLevel = pollutionLevel;
	this->productionCapacity = productionCapacity;
	this->bType = "Industrial";

}


//get type of building
string IndustrialBuilding::getType() const{
	return this->bType;
}


//update impacts by calculating economic impact, resource consumption and satisfaction impact
void IndustrialBuilding::updateImpacts() {
	calculateEconomicImpact();
	calculateResourceConsumption();
	calculateSatisfactionImpact();
}

//upgrade tech level of the building
void IndustrialBuilding::upgradeTech(float techLevel) {
	productionCapacity += techLevel; //maybe change this ,find better logic
}

//calculate economic impact of the building
void IndustrialBuilding::calculateEconomicImpact() {
	economicGrowth = productionCapacity * 0.3f;
}


//calculate resource consumption of the building
void IndustrialBuilding::calculateResourceConsumption() {
	resourceConsumption = productionCapacity * 0.2f;
}

//calculate satisfaction impact of the building
void IndustrialBuilding::calculateSatisfactionImpact() {
	//citizenSatisfaction = productionCapacity * 0.05;
	citizenSatisfaction = -pollutionLevel * 0.1f;
}


//construct the building
void IndustrialBuilding::construct() {
	std::cout<<"============================================================\n";
	   std::cout << "Constructing Industrial Building: " << name << std::endl;
    std::cout << "Area: " << area << "\nFloors: " << floors << "\nCapacity: " << capacity << std::endl;
    std::cout << "Production Capacity: " << productionCapacity << "\nPollution Level: " << pollutionLevel << std::endl;
    
std::cout<<"============================================================\n";
}
