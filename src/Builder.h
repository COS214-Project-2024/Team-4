/**
 * @file Builder.h
 * @brief Definition of the Builder class.
 * 
 * This file contains the definition of the Builder class, which is a base class for all builders.
 * It includes methods to set various properties of a building such as name, area, floors, capacity,
 * citizen satisfaction, economic growth, and resource consumption.
 * 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @note This file is part of a project for managing city buildings and their properties.
 */

#ifndef BUILDER_H
#define BUILDER_H

#include <string>
#include "Building.h"
#include <memory>

using namespace std;

/**
 * @class Builder
 * @brief Base class for all builders.
 * 
 * This class provides methods to set various properties of a building such as name, area, floors, capacity,
 * citizen satisfaction, economic growth, and resource consumption.
 */
class Builder {

protected:
    string name; ///< Name of the building
    float area = 0.0f; ///< Area of the building
    int floors = 0; ///< Number of floors in the building
    int capacity = 0; ///< Capacity of the building
    float citizenSatisfaction = 0.0f; ///< Citizen satisfaction of the building
    float economicGrowth = 0.0f; ///< Economic growth of the building
    float resourceConsumption = 0.0f; ///< Resource consumption of the building

public:
    /**
     * @brief Sets the name of the building.
     * 
     * @param name The name of the building.
     * @return Builder& Reference to the Builder object.
     */
    Builder& setName(string name);

    /**
     * @brief Sets the area of the building.
     * 
     * @param area The area of the building.
     * @return Builder& Reference to the Builder object.
     */
    Builder& setArea(float area);

    /**
     * @brief Sets the number of floors in the building.
     * 
     * @param floors The number of floors in the building.
     * @return Builder& Reference to the Builder object.
     */
    Builder& setFloors(int floors);

    /**
     * @brief Sets the capacity of the building.
     * 
     * @param capacity The capacity of the building.
     * @return Builder& Reference to the Builder object.
     */
    Builder& setCapacity(int capacity);

    /**
     * @brief Sets the citizen satisfaction of the building.
     * 
     * @param citizenSatisfaction The citizen satisfaction of the building.
     * @return Builder& Reference to the Builder object.
     */
    Builder& setCitizenSatisfaction(float citizenSatisfaction);

    /**
     * @brief Sets the economic growth of the building.
     * 
     * @param economicGrowth The economic growth of the building.
     * @return Builder& Reference to the Builder object.
     */
    Builder& setEconomicGrowth(float economicGrowth);

    /**
     * @brief Sets the resource consumption of the building.
     * 
     * @param resourceConsumption The resource consumption of the building.
     * @return Builder& Reference to the Builder object.
     */
    Builder& setResourceConsumption(float resourceConsumption);

    /**
     * @brief Builds the building.
     * 
     * @return std::unique_ptr<Building> A unique pointer to the built building.
     */
    virtual std::unique_ptr<Building> build() = 0;

    /**
     * @brief Virtual destructor for the Builder class.
     */
    virtual ~Builder() = default;
};

#endif // BUILDER_H