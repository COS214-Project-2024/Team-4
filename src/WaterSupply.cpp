/**
 * @file WaterSupply.cpp
 * @brief Implementation of the WaterSupply class.
 * 
 * This file contains the implementation of the WaterSupply class, which handles water supply services for buildings.
 * 
 * @version 1.0
 * @date 2024-11-04
 * 
 * @note This file is part of a larger project that simulates the behavior of citizens and buildings in a city.
 */

#include "WaterSupply.h"
#include <iostream>

/**
 * @brief Constructor for the WaterSupply class.
 * 
 * @param mediator A pointer to the UtilityMediator for managing resources.
 */
WaterSupply::WaterSupply(UtilityMediator* mediator) : Utility(mediator) {}

/**
 * @brief Registers a building with the water supply service.
 * 
 * @param building A pointer to the building to be registered.
 */
void WaterSupply::registerBuilding(Building* building) {
    std::cout << "Building registered with WaterSupply.\n";
}

/**
 * @brief Supplies water to a building.
 * 
 * @param building A pointer to the building to receive water.
 */
void WaterSupply::supplyResources(Building* building) {
    if (mediator->requestResources(ResourceType::Water, 30)) {
        std::cout << "Water supplied to building.\n";
    } else {
        std::cout << "Insufficient water to supply to building.\n";
    }
}

/**
 * @brief Adjusts water supply services based on the new population size.
 * 
 * @param newPopulation The new population size.
 */
void WaterSupply::adjustForPopulation(int newPopulation) {
    std::cout << "Adjusting water supply based on new population size: " << newPopulation << "\n";
}

// /**
//  * @brief Adjusts water supply services based on a citizen's requirements.
//  * 
//  * @param citizen A pointer to the citizen whose requirements are being considered.
//  */
// void WaterSupply::adjustForCitizen(Citizen* citizen) {
//     std::cout << "Adjusting water supply based on citizen's requirements.\n";
// }