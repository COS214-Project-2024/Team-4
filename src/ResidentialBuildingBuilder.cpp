/**
 * @file ResidentialBuildingBuilder.cpp
 * @brief Implementation file for the ResidentialBuildingBuilder class.
 * 
 * This file contains the implementation of the ResidentialBuildingBuilder class, 
 * which is used to construct ResidentialBuilding objects with specific attributes.
 * 
 * @version 1.0
 * @date 2023-10-05
 */

#include "ResidentialBuildingBuilder.h"

/**
 * @brief Sets the number of residential units in the building.
 * 
 * @param unit The number of residential units.
 * @return A reference to the ResidentialBuildingBuilder object.
 */
ResidentialBuildingBuilder& ResidentialBuildingBuilder::setResidentialUnit(int unit) {
    this->residentialUnit = unit;
    return *this;
}

/**
 * @brief Sets the comfort level of the building.
 * 
 * @param comfort The comfort level.
 * @return A reference to the ResidentialBuildingBuilder object.
 */
ResidentialBuildingBuilder& ResidentialBuildingBuilder::setComfort(float comfort) {
    this->comfort = comfort;
    return *this;
}

/**
 * @brief Gets the number of residential units in the building.
 * 
 * @return The number of residential units.
 */
int ResidentialBuildingBuilder::getResidentialUnit() {
    return this->residentialUnit;
}

/**
 * @brief Gets the comfort level of the building.
 * 
 * @return The comfort level.
 */
float ResidentialBuildingBuilder::getComfort() {
    return this->comfort;
}

/**
 * @brief Builds the residential building and sets all the attributes of the building.
 * 
 * @return A unique pointer to the constructed ResidentialBuilding object.
 */
std::unique_ptr<Building> ResidentialBuildingBuilder::build() {
    return std::make_unique<ResidentialBuilding>(
        name, area, floors, capacity, citizenSatisfaction, economicGrowth,
        resourceConsumption, residentialUnit, comfort
    );
}

/**
 * @brief Constructs a new ResidentialBuildingBuilder object.
 */
ResidentialBuildingBuilder::ResidentialBuildingBuilder() {
    // Constructor implementation
}