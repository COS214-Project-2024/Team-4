/**
 * @file IndustrialBuildingBuilder.cpp
 * @brief Implementation of the IndustrialBuildingBuilder class.
 * @version 1.0
 * 
 * This file contains the implementation of the IndustrialBuildingBuilder class, which provides
 * methods to set attributes and build an IndustrialBuilding object.
 */

#include "IndustrialBuildingBuilder.h"

/**
 * @brief Sets the pollution level of the building.
 * @param level The pollution level to set.
 * @return Reference to the current IndustrialBuildingBuilder object.
 */
IndustrialBuildingBuilder& IndustrialBuildingBuilder::setPollutionLevel(float level) {
    this->pollutionLevel = level;
    return *this;
}

/**
 * @brief Sets the production capacity of the building.
 * @param capacity The production capacity to set.
 * @return Reference to the current IndustrialBuildingBuilder object.
 */
IndustrialBuildingBuilder& IndustrialBuildingBuilder::setProductionCapacity(float capacity) {
    this->productionCapacity = capacity;
    return *this;
}

/**
 * @brief Gets the pollution level of the building.
 * @return The pollution level of the building.
 */
float IndustrialBuildingBuilder::getPollutionLevel() {
    return this->pollutionLevel;
}

/**
 * @brief Gets the production capacity of the building.
 * @return The production capacity of the building.
 */
float IndustrialBuildingBuilder::getProductionCapacity() {
    return this->productionCapacity;
}

/**
 * @brief Builds the industrial building and sets all the attributes of the building.
 * @return A unique pointer to the constructed IndustrialBuilding object.
 */
std::unique_ptr<Building> IndustrialBuildingBuilder::build() {
    return std::make_unique<IndustrialBuilding>(
        name, area, floors, capacity, citizenSatisfaction, economicGrowth,
        resourceConsumption, productionCapacity, pollutionLevel
    );
}

/**
 * @brief Constructor for IndustrialBuildingBuilder.
 */
IndustrialBuildingBuilder::IndustrialBuildingBuilder() {
    // Constructor implementation
}