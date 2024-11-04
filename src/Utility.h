/**
 * @file Utility.h
 * @brief Declaration of the Utility class.
 * 
 * This file contains the declaration of the Utility class, which handles the management of resources for buildings.
 * 
 * @version 1.0
 * @date 2024-11-04
 * 
 * @note This file is part of a larger project that simulates the behavior of citizens and buildings in a city.
 */

#ifndef UTILITY_H
#define UTILITY_H

#include "Building.h"
#include "ResourceType.h"
#include "UtilityMediator.h"
#include <memory>

/**
 * @class Utility
 * @brief A class that represents a utility service in the city.
 * 
 * The Utility class is responsible for managing resources for buildings through a mediator.
 */
class Utility {
protected:
    UtilityMediator* mediator;  ///< Reference to the mediator for managing resources

public:
    /**
     * @brief Constructor for the Utility class.
     * 
     * @param mediator A pointer to the UtilityMediator for managing resources.
     */
    Utility(UtilityMediator* mediator) : mediator(mediator) {}

    /**
     * @brief Registers a building with the utility service.
     * 
     * @param building A pointer to the building to be registered.
     */
    virtual void registerBuilding(Building* building) = 0;

    /**
     * @brief Supplies resources to a building.
     * 
     * @param building A pointer to the building to receive resources.
     */
    virtual void supplyResources(Building* building) = 0;

    /**
     * @brief Adjusts the utility service for a new population size.
     * 
     * @param newPopulation The new population size.
     */
    virtual void adjustForPopulation(int newPopulation) = 0;

    /**
     * @brief Virtual destructor for the Utility class.
     */
    virtual ~Utility() = default;
};

#endif // UTILITY_H