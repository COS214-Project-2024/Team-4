#include "CommercialBuilding.h"

// Constructor
CommercialBuilding::CommercialBuilding(const std::string& name, float area, int floors, int capacity,
                                       float citizenSatisfaction, float economicGrowth, float resourceConsumption,
                                       int businessUnits, float customerTraffic)
    : Building(name, area, floors, capacity, citizenSatisfaction, economicGrowth, resourceConsumption),
      businessUnits(businessUnits), customerTraffic(customerTraffic), bType("Commercial") {}

// Destructor
CommercialBuilding::~CommercialBuilding() {
    // Destructor implementation (can be empty)
}

// Get type of building
std::string CommercialBuilding::getType() const {
    return this->bType;
}

// Update impacts by calculating economic impact, resource consumption, and satisfaction impact
void CommercialBuilding::updateImpacts() {
    calculateEconomicImpact();
    calculateResourceConsumption();
    calculateSatisfactionImpact();
}

// Update customer traffic
void CommercialBuilding::updateCustomer(int traffic) {
    customerTraffic += traffic;
}

// Calculate economic impact of the building
void CommercialBuilding::calculateEconomicImpact() {
    economicGrowth = businessUnits * customerTraffic * 0.1f;
}

// Calculate resource consumption of the building
void CommercialBuilding::calculateResourceConsumption() {
    resourceConsumption = businessUnits * 0.05f;
}

// Calculate satisfaction impact of the building
void CommercialBuilding::calculateSatisfactionImpact() {
    citizenSatisfaction = customerTraffic * 0.1f;
}

// Construct the building
void CommercialBuilding::construct() {
    std::cout << "============================================================\n";
    std::cout << "Constructing Commercial Building: " << name << std::endl;
    std::cout << "Area: " << area << "\nFloors: " << floors << "\nCapacity: " << capacity << std::endl;
    std::cout << "Business Units: " << businessUnits << "\nCustomer Traffic: " << customerTraffic << std::endl;
    std::cout << "============================================================\n";
}

// Pay taxes for the building
double CommercialBuilding::payTaxes(TaxType* taxType) {
    if (!business) {
        std::cout << "No business in the building to collect taxes from.\n";
        return 0.0;
    }

    double totalTax = business->payTaxes(taxType);
    std::cout << "Total taxes collected from building " << name << ": R" << totalTax << "\n";
    return totalTax;
}

// Undo collecting taxes from the building
void CommercialBuilding::undoCollectTaxes() {
    double tax = economicGrowth * 0.1;
    std::cout << "Refunded taxes from Commercial Building: " << name << " - Amount: " << tax << std::endl;
}

// Set business in the building
void CommercialBuilding::setBusiness(std::shared_ptr<Business> business) {
    this->business = business;
}

// Add citizen to the building
void CommercialBuilding::addCitizen(Citizen* citizen) {
    // Not implemented here
}

// Add business to the building
void CommercialBuilding::addBusiness(std::shared_ptr<Business> business) {
    this->business = business;
}

// Get business in the building
std::shared_ptr<Business> CommercialBuilding::getBusiness() const {
    return business;
}