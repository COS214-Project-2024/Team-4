/**
 * @file WaterSupply.h
 * @brief Declaration of the WaterSupply class.
 * 
 * This file contains the declaration of the WaterSupply class, which handles water supply services for buildings.
 * 
 * @version 1.0
 * @date 2024-11-04
 * 
 * @note This file is part of a larger project that simulates the behavior of citizens and buildings in a city.
 */

#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "Utility.h"

/**
 * @class WaterSupply
 * @brief A class that represents water supply services in the city.
 * 
 * The WaterSupply class is responsible for handling water supply services for buildings through a mediator.
 */
class WaterSupply : public Utility {

public:
    /**
     * @brief Constructor for the WaterSupply class.
     * 
     * @param mediator A pointer to the UtilityMediator for managing resources.
     */
    WaterSupply(UtilityMediator* mediator);

    /**
     * @brief Registers a building with the water supply service.
     * 
     * @param building A pointer to the building to be registered.
     */
    void registerBuilding(Building* building) override;

    /**
     * @brief Supplies water to a building.
     * 
     * @param building A pointer to the building to receive water.
     */
    void supplyResources(Building* building) override;

    /**
     * @brief Adjusts water supply services based on the new population size.
     * 
     * @param newPopulation The new population size.
     */
    void adjustForPopulation(int newPopulation) override;

    // /**
    //  * @brief Adjusts water supply services based on a citizen's requirements.
    //  * 
    //  * @param citizen A pointer to the citizen whose requirements are being considered.
    //  */
    // void adjustForCitizen(Citizen* citizen) override;
};

#endif // WATERSUPPLY_H