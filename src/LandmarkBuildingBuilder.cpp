/**
 * @file LandmarkBuildingBuilder.cpp
 * @brief Implementation of the LandmarkBuildingBuilder class.
 * @version 1.0
 * @date 2024-11-04
 * This file contains the implementation of the LandmarkBuildingBuilder class, which provides
 * methods to set attributes and build a LandmarkBuilding object.
 */

#include "LandmarkBuildingBuilder.h"

/**
 * @brief Gets the visitor capacity of the building.
 * @return The visitor capacity of the building.
 */
int LandmarkBuildingBuilder::getVisitorCapacity() {
    return this->visitorCapacity;
}

/**
 * @brief Sets the visitor capacity of the building.
 * @param visitorCapacity The visitor capacity to set.
 * @return Reference to the current LandmarkBuildingBuilder object.
 */
LandmarkBuildingBuilder& LandmarkBuildingBuilder::setVisitorCapacity(int visitorCapacity) {
    this->visitorCapacity = visitorCapacity;
    return *this;
}

/**
 * @brief Gets the cultural value of the building.
 * @return The cultural value of the building.
 */
float LandmarkBuildingBuilder::getCulturalValue() {
    return this->culturalValue;
}

/**
 * @brief Sets the cultural value of the building.
 * @param culturalValue The cultural value to set.
 * @return Reference to the current LandmarkBuildingBuilder object.
 */
LandmarkBuildingBuilder& LandmarkBuildingBuilder::setCulturalValue(float culturalValue) {
    this->culturalValue = culturalValue;
    return *this;
}

/**
 * @brief Gets whether the building is historic.
 * @return True if the building is historic, false otherwise.
 */
bool LandmarkBuildingBuilder::getIsHistoric() {
    return this->isHistoric;
}

/**
 * @brief Sets whether the building is historic.
 * @param isHistoric True if the building is historic, false otherwise.
 * @return Reference to the current LandmarkBuildingBuilder object.
 */
LandmarkBuildingBuilder& LandmarkBuildingBuilder::setIsHistoric(bool isHistoric) {
    this->isHistoric = isHistoric;
    return *this;
}

/**
 * @brief Builds the landmark building and sets all the attributes of the building.
 * @return A unique pointer to the constructed LandmarkBuilding object.
 */
std::unique_ptr<Building> LandmarkBuildingBuilder::build() {
    return std::make_unique<LandmarkBuilding>(
        name, area, floors, capacity, citizenSatisfaction,
        economicGrowth, resourceConsumption, visitorCapacity, culturalValue, isHistoric
    );
}

/**
 * @brief Constructor for LandmarkBuildingBuilder.
 */
LandmarkBuildingBuilder::LandmarkBuildingBuilder() {
    // Constructor implementation
}