/**
 * @file Builder.cpp
 * @brief Implementation of the Builder class.
 * 
 * This file contains the implementation of the Builder class, which is a base class for all builders.
 * It includes methods to set various properties of a building such as name, area, floors, capacity,
 * citizen satisfaction, economic growth, and resource consumption.
 * 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @note This file is part of a project for managing city buildings and their properties.
 */

#include "Builder.h"
//base class for all builders

/**
 * @brief Sets the name of the building.
 * 
 * @param name The name of the building.
 * @return Builder& Reference to the Builder object.
 */
Builder& Builder::setName(string name) {
    this->name = name;
    return *this;
}

/**
 * @brief Sets the area of the building.
 * 
 * @param area The area of the building.
 * @return Builder& Reference to the Builder object.
 */
Builder& Builder::setArea(float area) {
    this->area = area;
    return *this;
}

/**
 * @brief Sets the number of floors in the building.
 * 
 * @param floors The number of floors in the building.
 * @return Builder& Reference to the Builder object.
 */
Builder& Builder::setFloors(int floors) {
    this->floors = floors;
    return *this;
}

/**
 * @brief Sets the capacity of the building.
 * 
 * @param capacity The capacity of the building.
 * @return Builder& Reference to the Builder object.
 */
Builder& Builder::setCapacity(int capacity) {
    this->capacity = capacity;
    return *this;
}

/**
 * @brief Sets the citizen satisfaction of the building.
 * 
 * @param citizenSatisfaction The citizen satisfaction of the building.
 * @return Builder& Reference to the Builder object.
 */
Builder& Builder::setCitizenSatisfaction(float citizenSatisfaction) {
    this->citizenSatisfaction = citizenSatisfaction;
    return *this;
}

/**
 * @brief Sets the economic growth of the building.
 * 
 * @param economicGrowth The economic growth of the building.
 * @return Builder& Reference to the Builder object.
 */
Builder& Builder::setEconomicGrowth(float economicGrowth) {
    this->economicGrowth = economicGrowth;
    return *this;
}

/**
 * @brief Sets the resource consumption of the building.
 * 
 * @param resourceConsumption The resource consumption of the building.
 * @return Builder& Reference to the Builder object.
 */
Builder& Builder::setResourceConsumption(float resourceConsumption) {
    this->resourceConsumption = resourceConsumption;
    return *this;
}