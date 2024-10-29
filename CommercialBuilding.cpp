#include "CommercialBuilding.h"

CommercialBuilding::CommercialBuilding(const std::string& name, float area, int floors, int capacity,
							float citizenSatisfaction, float economicGrowth, float resourceConsumption,
							int businessUnits, float customerTraffic):
 Building(name, area, floors, capacity, citizenSatisfaction, economicGrowth, resourceConsumption)
 {
	this->businessUnits = businessUnits;
	this->customerTraffic = customerTraffic;
	this->bType = "Commercial";

}

string CommercialBuilding::getType() const{
	return this->bType;
}

void CommercialBuilding::updateImpacts() {
	calculateEconomicImpact();
	calculateResourceConsumption();
	calculateSatisfactionImpact();
}

void CommercialBuilding::updateCustomer(int traffic) {
	customerTraffic += traffic;
}

void CommercialBuilding::calculateEconomicImpact() {
	economicGrowth = businessUnits * customerTraffic * 0.1f;
}

void CommercialBuilding::calculateResourceConsumption() {
	resourceConsumption = businessUnits * 0.05f;
}

void CommercialBuilding::calculateSatisfactionImpact() {
	citizenSatisfaction = customerTraffic * 0.1f;
}

void CommercialBuilding::construct() {
	 std::cout << "Constructing Commercial Building: " << name << std::endl;
    std::cout << "Area: " << area << ", Floors: " << floors << ", Capacity: " << capacity << std::endl;
    std::cout << "Business Units: " << businessUnits << ", Customer Traffic: " << customerTraffic << std::endl;
    std::cout << "Commercial Building constructed successfully!" << std::endl;

}