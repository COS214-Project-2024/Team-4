#include "ResidentialBuilding.h"

//constructor
ResidentialBuilding::ResidentialBuilding(const std::string& name, float area, int floors,
                                         int capacity, float citizenSatisfaction,
                                         float economicGrowth, float resourceConsumption,
                                         int residentialUnits, float comfortLevel)
    : Building(name, area, floors, capacity, citizenSatisfaction, economicGrowth, resourceConsumption),
      residentialUnits(residentialUnits), comfortLevel(comfortLevel), bType("Residential") {}


string ResidentialBuilding::getType() const{
	return bType;
}

void ResidentialBuilding::updateImpacts() {
	calculateEconomicImpact();
    calculateResourceConsumption();
    calculateSatisfactionImpact();
}

void ResidentialBuilding::upgradeComfort(float comfort) {
	comfortLevel += comfort;
}

void ResidentialBuilding::calculateEconomicImpact() {
	 economicGrowth = residentialUnits * comfortLevel * 0.5f;
}

void ResidentialBuilding::calculateResourceConsumption() {
	resourceConsumption = residentialUnits * 0.05f;
}

void ResidentialBuilding::calculateSatisfactionImpact() {
	citizenSatisfaction = comfortLevel * 0.2f;
}

void ResidentialBuilding::construct() {
	  std::cout << "Constructing Residential Building: " << name << std::endl;
    std::cout << "Area: " << area << ", Floors: " << floors << ", Capacity: " << capacity << std::endl;
    std::cout << "Residential Units: " << residentialUnits << ", Comfort Level: " << comfortLevel << std::endl;
    std::cout << "Residential Building constructed successfully!" << std::endl;

}