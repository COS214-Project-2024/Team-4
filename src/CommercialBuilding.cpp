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

// Pay Taxes for the Building
double CommercialBuilding::payTaxes(TaxType* taxType) {
    if (!business) {
        std::cout << "No business in the building to collect taxes from.\n";
        return 0.0;
    }

    double totalTax = business->payTaxes(taxType);
    std::cout << "Total taxes collected from building " << name << ": $" << totalTax << "\n";
    return totalTax;
}

// Undo Collecting Taxes from the Building
void CommercialBuilding::undoCollectTaxes() {
    double tax = economicGrowth * 0.1;
    std::cout << "Refunded taxes from Commercial Building: " << name << " - Amount: " << tax << std::endl;
}

// Set Business in the Building
void CommercialBuilding::setBusiness(Business* business) {
    this->business = business;
}