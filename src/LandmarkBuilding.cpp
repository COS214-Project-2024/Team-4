/**
 * @file LandmarkBuilding.cpp
 * @brief Implementation of the LandmarkBuilding class.
 * @version 1.0
 * 
 * This file contains the implementation of the LandmarkBuilding class, which represents a landmark building
 * with specific attributes and behaviors.
 */

#include "LandmarkBuilding.h"

/**
 * @brief Constructor for LandmarkBuilding.
 * @param name The name of the landmark building.
 * @param area The area of the landmark building.
 * @param floors The number of floors in the landmark building.
 * @param capacity The capacity of the landmark building.
 * @param citizenSatisfaction The citizen satisfaction level.
 * @param economicGrowth The economic growth contributed by the building.
 * @param resourceConsumption The resource consumption of the building.
 * @param visitorsPerDay The number of visitors per day.
 * @param entranceFee The entrance fee for the landmark building.
 * @param hasGuidedTours Indicates if the landmark building has guided tours.
 */
LandmarkBuilding::LandmarkBuilding(const std::string& name, float area, int floors, int capacity,
                                   float citizenSatisfaction, float economicGrowth, float resourceConsumption,
                                   int visitorsPerDay, float entranceFee, bool hasGuidedTours)
    : Building(name, area, floors, capacity, citizenSatisfaction, economicGrowth, resourceConsumption) {
    this->visitorCapacity = visitorCapacity;
    this->culturalValue = culturalValue;
    this->isHistoric = isHistoric;
    this->bType = "Landmark";
}

/**
 * @brief Gets the type of the building.
 * @return The type of the building.
 */
string LandmarkBuilding::getType() const {
    return this->bType;
}

/**
 * @brief Updates the impacts of the building by calculating economic impact, resource consumption, and satisfaction impact.
 */
void LandmarkBuilding::updateImpacts() {
    calculateEconomicImpact();
    calculateResourceConsumption();
    calculateSatisfactionImpact();
}

/**
 * @brief Hosts an event in the building.
 * @param visitors The number of visitors attending the event.
 */
void LandmarkBuilding::hostEvent(int visitors) {
    visitorCapacity += visitors;
    culturalValue += 5.0f;
}

/**
 * @brief Calculates the economic impact of the building.
 */
void LandmarkBuilding::calculateEconomicImpact() {
    economicGrowth += visitorCapacity * culturalValue;
}

/**
 * @brief Calculates the resource consumption of the building.
 */
void LandmarkBuilding::calculateResourceConsumption() {
    resourceConsumption += visitorCapacity * 0.1;
}

/**
 * @brief Calculates the satisfaction impact of the building.
 */
void LandmarkBuilding::calculateSatisfactionImpact() {
    citizenSatisfaction += visitorCapacity * 0.01;
}

/**
 * @brief Constructs the building.
 */
void LandmarkBuilding::construct() {
    std::cout << "============================================================\n";
    std::cout << "Constructing Landmark Building: " << name << std::endl;
    std::cout << "Area: " << area << "\nFloors: " << floors << "\nCapacity: " << capacity << std::endl;
    std::cout << "Visitor Capacity: " << visitorCapacity << "\nCultural Value: " << culturalValue;
    if (isHistoric) {
        std::cout << "\nHistoric: Yes\n";
    } else {
        std::cout << "\nHistoric: No\n";
    }
    std::cout << "============================================================\n";
}

/**
 * @brief Pays taxes for the building.
 * @param taxType The type of tax to calculate.
 * @return The amount of taxes paid.
 */
double LandmarkBuilding::payTaxes(TaxType* taxType) {
    return 0.0;
}

/**
 * @brief Undoes the tax collection from the building.
 */
void LandmarkBuilding::undoCollectTaxes() {
    // Not needed
}