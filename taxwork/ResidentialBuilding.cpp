// ResidentialBuilding.cpp

#include "ResidentialBuilding.h"
#include <iostream>

// Constructor
ResidentialBuilding::ResidentialBuilding(const std::string& name, float area, int floors,
                                         int capacity, float citizenSatisfaction,
                                         float economicGrowth, float resourceConsumption,
                                         int residentialUnits, float comfortLevel)
    : Building(name, area, floors, capacity, citizenSatisfaction, economicGrowth, resourceConsumption),
      residentialUnits(residentialUnits), comfortLevel(comfortLevel), bType("Residential") {}

// Get Type of Building
std::string ResidentialBuilding::getType() const {
    return bType;
}

// Update Impacts
void ResidentialBuilding::updateImpacts() {
    calculateEconomicImpact();
    calculateResourceConsumption();
    calculateSatisfactionImpact();
}

// Upgrade Comfort Level
void ResidentialBuilding::upgradeComfort(float comfort) {
    comfortLevel += comfort;
}

// Calculate Economic Impact
void ResidentialBuilding::calculateEconomicImpact() {
    economicGrowth = residentialUnits * comfortLevel * 0.5f;
}

// Calculate Resource Consumption
void ResidentialBuilding::calculateResourceConsumption() {
    resourceConsumption = residentialUnits * 0.05f;
}

// Calculate Satisfaction Impact
void ResidentialBuilding::calculateSatisfactionImpact() {
    citizenSatisfaction = comfortLevel * 0.2f;
}

// Construct Building
void ResidentialBuilding::construct() {
    std::cout << "============================================================\n";
    std::cout << "Constructing Residential Building: " << name << std::endl;
    std::cout << "Area: " << area << "\nFloors: " << floors << "\nCapacity: " << capacity << std::endl;
    std::cout << "Residential Units: " << residentialUnits << "\nComfort Level: " << comfortLevel << std::endl;
    std::cout << "============================================================\n";
}

// Pay Taxes for the Building
double ResidentialBuilding::payTaxes(TaxType* taxType) {
    double totalTax = 0.0;

    std::cout << "Collecting taxes from Residential Building: " << name << "\n";

    for (const auto& citizen : residents) {
        totalTax += citizen->payTaxes(taxType);
    }

    if (totalTax > 0.0) {
        std::cout << "Total taxes collected from building " << name << ": $" << totalTax << "\n";
    } else {
        std::cout << "No taxes collected from building " << name << " (possibly on cooldown).\n";
    }

    return totalTax;
}

// Calculate Property Tax
double ResidentialBuilding::calculatePropertyTax() {
    propertyTax = residentialUnits * 0.1f;
    return propertyTax;
}

// Calculate Household Income
double ResidentialBuilding::calculateHouseholdIncome() {
    householdIncome = residentialUnits * 1000.0f;
    return householdIncome;
}

// Add Residents to the Building
void ResidentialBuilding::addResidents(std::shared_ptr<Citizen> citizen) {
    residents.push_back(citizen);
}

// Undo Collecting Taxes from the Building
void ResidentialBuilding::undoCollectTaxes() {
    propertyTax = 0;
    householdIncome = 0;
}

// Get Residential Units
int ResidentialBuilding::getResidentialUnits() const {
    return residentialUnits;
}