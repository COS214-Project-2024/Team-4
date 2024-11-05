/**
 * @file WasteManagement.cpp
 * @brief Implementation of the WasteManagement class.
 * 
 * This file contains the implementation of the WasteManagement class, which handles waste management services for buildings.
 * 
 * @version 1.0
 * @date 2024-11-04
 * 
 * @note This file is part of a larger project that simulates the behavior of citizens and buildings in a city.
 */

#include "WasteManagement.h"
#include <iostream>

/**
 * @brief Constructor for the WasteManagement class.
 * 
 * @param mediator A pointer to the UtilityMediator for managing resources.
 */
WasteManagement::WasteManagement(UtilityMediator* mediator) : Utility(mediator) {}

/**
 * @brief Registers a building with the waste management service.
 * 
 * @param building A pointer to the building to be registered.
 */
void WasteManagement::registerBuilding(Building* building) {
    std::cout << "Building registered with WasteManagement.\n";
}

/**
 * @brief Supplies waste management services to a building.
 * 
 * @param building A pointer to the building to receive waste management services.
 */
void WasteManagement::supplyResources(Building* building) {
    std::cout << "Waste management service provided to building.\n";
}

/**
 * @brief Adjusts waste management services based on the new population size.
 * 
 * @param newPopulation The new population size.
 */
void WasteManagement::adjustForPopulation(int newPopulation) {
    std::cout << "Adjusting waste management based on new population size: " << newPopulation << "\n";
}

// /**
//  * @brief Adjusts waste management services based on a citizen's requirements.
//  * 
//  * @param citizen A pointer to the citizen whose requirements are being considered.
//  */
// void WasteManagement::adjustForCitizen(Citizen* citizen) {
//     std::cout << "Adjusting waste management based on citizen's requirements.\n";
// }