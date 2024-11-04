/**
 * @file ResidentialBuilding.cpp
 * @brief Implementation of the ResidentialBuilding class.
 * @version 1.0
 * 
 * This file contains the implementation of the ResidentialBuilding class, which represents a residential building
 * with specific attributes and behaviors.
 */

#include "ResidentialBuilding.h"
#include <iostream>

/**
 * @brief Constructor for ResidentialBuilding.
 * @param name The name of the residential building.
 * @param area The area of the residential building.
 * @param floors The number of floors in the residential building.
 * @param capacity The capacity of the residential building.
 * @param citizenSatisfaction The citizen satisfaction level.
 * @param economicGrowth The economic growth contributed by the building.
 * @param resourceConsumption The resource consumption of the building.
 * @param residentialUnits The number of residential units in the building.
 * @param comfortLevel The comfort level of the building.
 */
ResidentialBuilding::ResidentialBuilding(const std::string& name, float area, int floors,
                                         int capacity, float citizenSatisfaction,
                                         float economicGrowth, float resourceConsumption,
                                         int residentialUnits, float comfortLevel)
    : Building(name, area, floors, capacity, citizenSatisfaction, economicGrowth, resourceConsumption),
      residentialUnits(residentialUnits), comfortLevel(comfortLevel), bType("Residential") {}

/**
 * @brief Gets the type of the building.
 * @return The type of the building.
 */
std::string ResidentialBuilding::getType() const {
    return bType;
}

/**
 * @brief Updates the impacts of the building by calculating economic impact, resource consumption, and satisfaction impact.
 */
void ResidentialBuilding::updateImpacts() {
    calculateEconomicImpact();
    calculateResourceConsumption();
    calculateSatisfactionImpact();
}

/**
 * @brief Upgrades the comfort level of the building.
 * @param comfort The new comfort level to upgrade to.
 */
void ResidentialBuilding::upgradeComfort(float comfort) {
    comfortLevel += comfort;
}

/**
 * @brief Calculates the economic impact of the building.
 */
void ResidentialBuilding::calculateEconomicImpact() {
    economicGrowth = residentialUnits * comfortLevel * 0.5f;
}

/**
 * @brief Calculates the resource consumption of the building.
 */
void ResidentialBuilding::calculateResourceConsumption() {
    resourceConsumption = residentialUnits * 0.05f;
}

/**
 * @brief Calculates the satisfaction impact of the building.
 */
void ResidentialBuilding::calculateSatisfactionImpact() {
    citizenSatisfaction = comfortLevel * 0.2f;
}

/**
 * @brief Constructs the building.
 */
void ResidentialBuilding::construct() {
    std::cout << "============================================================\n";
    std::cout << "Constructing Residential Building: " << name << std::endl;
    std::cout << "Area: " << area << "\nFloors: " << floors << "\nCapacity: " << capacity << std::endl;
    std::cout << "Residential Units: " << residentialUnits << "\nComfort Level: " << comfortLevel << std::endl;
    std::cout << "============================================================\n";
}

/**
 * @brief Pays taxes for the building.
 * @param taxType The type of tax to calculate.
 * @return The amount of taxes paid.
 */
double ResidentialBuilding::payTaxes(TaxType* taxType) {
    double totalIncomeTax = 0.0;
    double totalPropertyTax = 0.0;
    if (taxType->getTaxType() == 'I') {
        std::cout << "Collecting Income taxes from Residential Building: " << name << "\n";
        for (const auto& citizen : residents) {
            double citizenTax = citizen->payTaxes(taxType);
            totalIncomeTax += citizenTax;
        }
        std::cout << "Total Income taxes collected from building " << name << ": $" << totalIncomeTax << "\n"; 
    } else if (taxType->getTaxType() == 'P') {
        std::cout << "Collecting Property taxes from Residential Building: " << name << "\n";
        for (const auto& citizen : residents) {
            double citizenTax = citizen->payTaxes(taxType);
            totalPropertyTax += citizenTax;
        }
        std::cout << "Total Property taxes collected from building " << name << ": $" << totalPropertyTax << "\n";
    } else {
        std::cout << "Cannot collect taxes of this type\n";
    }
    totalTaxCollected += totalIncomeTax + totalPropertyTax;
    return totalTaxCollected;
}

/**
 * @brief Calculates the property tax for the building.
 * @return The calculated property tax.
 */
double ResidentialBuilding::calculatePropertyTax() {
    propertyTax = residentialUnits * 0.1f;
    return propertyTax;
}

/**
 * @brief Adds residents to the building.
 * @param citizen Pointer to the citizen to be added.
 */
void ResidentialBuilding::addResidents(Citizen* citizen) {
    residents.push_back(citizen);
}

/**
 * @brief Undoes the tax collection from the building.
 */
void ResidentialBuilding::undoCollectTaxes() {
    propertyTax = 0;
}

/**
 * @brief Gets the number of residential units in the building.
 * @return The number of residential units.
 */
int ResidentialBuilding::getResidentialUnits() const {
    return residentialUnits;
}