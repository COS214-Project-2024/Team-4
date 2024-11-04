/**
 * @file IndustrialBuilding.cpp
 * @brief Implementation of the IndustrialBuilding class.
 * @version 1.0
 * 
 * This file contains the implementation of the IndustrialBuilding class, which represents an industrial building
 * with specific attributes and behaviors.
 */

#include "IndustrialBuilding.h"

/**
 * @brief Constructor for IndustrialBuilding.
 * @param name The name of the industrial building.
 * @param area The area of the industrial building.
 * @param floors The number of floors in the industrial building.
 * @param capacity The capacity of the industrial building.
 * @param citizenSatisfaction The citizen satisfaction level.
 * @param economicGrowth The economic growth contributed by the building.
 * @param resourceConsumption The resource consumption of the building.
 * @param pollutionLevel The pollution level of the building.
 * @param productionCapacity The production capacity of the building.
 */
IndustrialBuilding::IndustrialBuilding(const std::string& name, float area, int floors, int capacity,
                        float citizenSatisfaction, float economicGrowth, float resourceConsumption,
                        float pollutionLevel, float productionCapacity)
    : Building(name, area, floors, capacity, citizenSatisfaction, economicGrowth, resourceConsumption) {
    this->pollutionLevel = pollutionLevel;
    this->productionCapacity = productionCapacity;
    this->bType = "Industrial";
}

/**
 * @brief Gets the type of the building.
 * @return The type of the building.
 */
std::string IndustrialBuilding::getType() const {
    return this->bType;
}

/**
 * @brief Updates the impacts of the building by calculating economic impact, resource consumption, and satisfaction impact.
 */
void IndustrialBuilding::updateImpacts() {
    calculateEconomicImpact();
    calculateResourceConsumption();
    calculateSatisfactionImpact();
}

/**
 * @brief Upgrades the technology level of the building.
 * @param techLevel The new technology level to upgrade to.
 */
void IndustrialBuilding::upgradeTech(float techLevel) {
    productionCapacity += techLevel; // Adjust logic as needed
}

/**
 * @brief Calculates the economic impact of the building.
 */
void IndustrialBuilding::calculateEconomicImpact() {
    economicGrowth = productionCapacity * 0.3f;
}

/**
 * @brief Calculates the resource consumption of the building.
 */
void IndustrialBuilding::calculateResourceConsumption() {
    resourceConsumption = productionCapacity * 0.2f;
}

/**
 * @brief Calculates the satisfaction impact of the building.
 */
void IndustrialBuilding::calculateSatisfactionImpact() {
    citizenSatisfaction = -pollutionLevel * 0.1f;
}

/**
 * @brief Constructs the building.
 */
void IndustrialBuilding::construct() {
    std::cout << "============================================================\n";
    std::cout << "Constructing Industrial Building: " << name << std::endl;
    std::cout << "Area: " << area << "\nFloors: " << floors << "\nCapacity: " << capacity << std::endl;
    std::cout << "Production Capacity: " << productionCapacity << "\nPollution Level: " << pollutionLevel << std::endl;
    std::cout << "============================================================\n";
}

/**
 * @brief Pays taxes for the building.
 * @param taxType The type of tax to calculate.
 * @return The amount of taxes paid.
 */
double IndustrialBuilding::payTaxes(TaxType* taxType) {
    double tax = economicGrowth * taxType->getTaxRate();
    std::cout << "Collected taxes from Industrial Building: " << name << " - Amount: " << tax << std::endl;
    return tax;
}

/**
 * @brief Undoes the tax collection from the building.
 */
void IndustrialBuilding::undoCollectTaxes() {
    std::cout << "Undoing tax collection from Industrial Building: " << name << std::endl;
}