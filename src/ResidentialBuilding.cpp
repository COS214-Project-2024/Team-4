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
// Update the ResidentialBuilding::payTaxes method:
double ResidentialBuilding::payTaxes(TaxType* taxType) {
     double totalIncomeTax = 0.0;
     double totalPropertyTax = 0.0;
    if (taxType->getTaxType() =='I'){
           std::cout << "Collecting Income taxes from Residential Building: " << name << "\n";
    for (const auto& citizen : residents) {
        double citizenTax = citizen->payTaxes(taxType);
        totalIncomeTax += citizenTax;
    }
    std::cout << "Total Income taxes collected from building " << name << ": R" << totalIncomeTax << "\n"; 
    }else if (taxType->getTaxType() =='P'){
       std::cout << "Collecting Property taxes from Residential Building: " << name << "\n";
    for (const auto& citizen : residents) {
        double citizenTax = citizen->payTaxes(taxType);
        totalPropertyTax += citizenTax;
    }
    std::cout << "Total Property taxes collected from building " << name << ": $" << totalPropertyTax << "\n";
    }else{
        std::cout << "cannot collect taxes of this type\n";
    }
    totalTaxCollected += totalIncomeTax+totalPropertyTax;
    return totalTaxCollected;
}
// Calculate Property Tax
double ResidentialBuilding::calculatePropertyTax() {
    propertyTax = residentialUnits * 0.1f;
    return propertyTax;
}

// Add Residents to the Building
void ResidentialBuilding::addResidents(Citizen* citizen) {
    residents.push_back(citizen);
}

// Undo Collecting Taxes from the Building
void ResidentialBuilding::undoCollectTaxes() {
    propertyTax = 0;
}

// Get Residential Units
int ResidentialBuilding::getResidentialUnits() const {
    return residentialUnits;
}

void ResidentialBuilding::addCitizen(Citizen* citizen) {
 if (citizen != nullptr) {
        residents.push_back(citizen);
    }
}
void ResidentialBuilding::addBusiness(Business* business) {
    // Do nothing
}
//END ResidentialBuilding.cpp ====================================================================================