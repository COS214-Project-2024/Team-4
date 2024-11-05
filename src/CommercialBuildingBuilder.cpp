/**
 * @file CommercialBuildingBuilder.cpp
 * @brief Implementation of the CommercialBuildingBuilder class.
 *
 * This file contains the implementation of the CommercialBuildingBuilder class which builds commercial buildings.
 * @date 2024-11-04
 * @version 1.0
 */

#include "CommercialBuildingBuilder.h"

/**
 * @brief Sets the number of business units in the building.
 * 
 * @param units The number of business units.
 * @return Reference to the current builder object.
 */
CommercialBuildingBuilder& CommercialBuildingBuilder::setBusinessUnits(int units) {
    this->businessUnits = units;
    return *this;
}

/**
 * @brief Gets the number of business units in the building.
 * 
 * @return The number of business units.
 */
int CommercialBuildingBuilder::getBusinessUnits() {
    return this->businessUnits;
}

/**
 * @brief Gets the customer traffic in the building.
 * 
 * @return The customer traffic.
 */
float CommercialBuildingBuilder::getCustomerTraffic() {
    return this->customerTraffic;
}

/**
 * @brief Sets the customer traffic in the building.
 * 
 * @param traffic The customer traffic.
 * @return Reference to the current builder object.
 */
CommercialBuildingBuilder& CommercialBuildingBuilder::setCustomerTraffic(float traffic) {
    this->customerTraffic = traffic;
    return *this;
}

/**
 * @brief Builds the commercial building and sets all the attributes of the building.
 * 
 * @return A unique pointer to the built CommercialBuilding object.
 */
std::unique_ptr<Building> CommercialBuildingBuilder::build() {
    return std::make_unique<CommercialBuilding>(
        name, area, floors, capacity, citizenSatisfaction, economicGrowth,
        resourceConsumption, businessUnits, customerTraffic
    );
}

/**
 * @brief Default constructor for CommercialBuildingBuilder.
 */
CommercialBuildingBuilder::CommercialBuildingBuilder() {
    // Constructor implementation (can be empty)
}