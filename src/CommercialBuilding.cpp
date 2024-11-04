/**
 * @file CommercialBuilding.cpp
 * @brief Implementation of the CommercialBuilding class.
 *
 * This file contains the implementation of the CommercialBuilding class which manages commercial buildings.
 * @date 2024-11-04
 * @version 1.0
 */

#include "CommercialBuilding.h"

// Constructor
/**
 * @brief Constructor for CommercialBuilding.
 *
 * Initializes the commercial building with the given parameters.
 * 
 * @param name The name of the building.
 * @param area The area of the building.
 * @param floors The number of floors in the building.
 * @param capacity The capacity of the building.
 * @param citizenSatisfaction The citizen satisfaction level.
 * @param economicGrowth The economic growth impact.
 * @param resourceConsumption The resource consumption level.
 * @param businessUnits The number of business units in the building.
 * @param customerTraffic The customer traffic level.
 */
CommercialBuilding::CommercialBuilding(const std::string& name, float area, int floors, int capacity,
                            float citizenSatisfaction, float economicGrowth, float resourceConsumption,
                            int businessUnits, float customerTraffic):
 Building(name, area, floors, capacity, citizenSatisfaction, economicGrowth, resourceConsumption)
 {
    this->businessUnits = businessUnits;
    this->customerTraffic = customerTraffic;
    this->bType = "Commercial";

}

/**
 * @brief Destructor for CommercialBuilding.
 */
CommercialBuilding::~CommercialBuilding() {
    // Destructor implementation (can be empty)
}

// Get type of building
/**
 * @brief Gets the type of the building.
 * 
 * @return The type of the building.
 */
std::string CommercialBuilding::getType() const{
    return this->bType;
}

// Update impacts by calculating economic impact, resource consumption and satisfaction impact
/**
 * @brief Updates the impacts of the building.
 *
 * Calculates the economic impact, resource consumption, and satisfaction impact.
 */
void CommercialBuilding::updateImpacts() {
    calculateEconomicImpact();
    calculateResourceConsumption();
    calculateSatisfactionImpact();
}

// Update customer traffic
/**
 * @brief Updates the customer traffic.
 * 
 * @param traffic The amount of traffic to add.
 */
void CommercialBuilding::updateCustomer(int traffic) {
    customerTraffic += traffic;
}

// Calculate economic impact of the building
/**
 * @brief Calculates the economic impact of the building.
 */
void CommercialBuilding::calculateEconomicImpact() {
    economicGrowth = businessUnits * customerTraffic * 0.1f;
}

// Calculate resource consumption of the building
/**
 * @brief Calculates the resource consumption of the building.
 */
void CommercialBuilding::calculateResourceConsumption() {
    resourceConsumption = businessUnits * 0.05f;
}

// Calculate satisfaction impact of the building
/**
 * @brief Calculates the satisfaction impact of the building.
 */
void CommercialBuilding::calculateSatisfactionImpact() {
    citizenSatisfaction = customerTraffic * 0.1f;
}

/**
 * @brief Constructs the commercial building.
 */
void CommercialBuilding::construct() {
    std::cout<<"============================================================\n";
     std::cout << "Constructing Commercial Building: " << name << std::endl;
    std::cout << "Area: " << area << "\nFloors: " << floors << "\nCapacity: " << capacity << std::endl;
    std::cout << "Business Units: " << businessUnits << "\nCustomer Traffic: " << customerTraffic << std::endl;
    std::cout<<"============================================================\n";

}

// Pay Taxes for the Building
/**
 * @brief Pays taxes for the building.
 * 
 * @param taxType Pointer to the TaxType object.
 * @return The total amount of taxes collected.
 */
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
/**
 * @brief Undoes the tax collection from the building.
 */
void CommercialBuilding::undoCollectTaxes() {
    double tax = economicGrowth * 0.1;
    std::cout << "Refunded taxes from Commercial Building: " << name << " - Amount: " << tax << std::endl;
}

// Set Business in the Building
/**
 * @brief Sets the business in the building.
 * 
 * @param business Pointer to the Business object.
 */
void CommercialBuilding::setBusiness(Business* business) {
    this->business = business;
}