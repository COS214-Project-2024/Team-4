#include "CommercialBuilding.h"

//constructor
CommercialBuilding::CommercialBuilding(const std::string& name, float area, int floors, int capacity,
							float citizenSatisfaction, float economicGrowth, float resourceConsumption,
							int businessUnits, float customerTraffic):
 Building(name, area, floors, capacity, citizenSatisfaction, economicGrowth, resourceConsumption)
 {
	this->businessUnits = businessUnits;
	this->customerTraffic = customerTraffic;
	this->bType = "Commercial";

}

//get type of building
string CommercialBuilding::getType() const{
	return this->bType;
}

//update impacts by calculating economic impact, resource consumption and satisfaction impact
void CommercialBuilding::updateImpacts() {
	calculateEconomicImpact();
	calculateResourceConsumption();
	calculateSatisfactionImpact();
}

//update customer traffic
void CommercialBuilding::updateCustomer(int traffic) {
	customerTraffic += traffic;
}

//calculate economic impact of the building
void CommercialBuilding::calculateEconomicImpact() {
	economicGrowth = businessUnits * customerTraffic * 0.1f;
}

//calculate resource consumption of the building
void CommercialBuilding::calculateResourceConsumption() {
	resourceConsumption = businessUnits * 0.05f;
}

//calculate satisfaction impact of the building
void CommercialBuilding::calculateSatisfactionImpact() {
	citizenSatisfaction = customerTraffic * 0.1f;
}

void CommercialBuilding::construct() {
	std::cout<<"============================================================\n";
	 std::cout << "Constructing Commercial Building: " << name << std::endl;
    std::cout << "Area: " << area << "\nFloors: " << floors << "\nCapacity: " << capacity << std::endl;
    std::cout << "Business Units: " << businessUnits << "\nCustomer Traffic: " << customerTraffic << std::endl;
	std::cout<<"============================================================\n";

}