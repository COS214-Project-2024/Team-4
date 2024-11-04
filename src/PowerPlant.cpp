/**
 * @file PowerPlant.cpp
 * @brief Implementation of the PowerPlant class.
 * @version 1.0
 * 
 * This file contains the implementation of the PowerPlant class, which represents a power plant
 * that supplies power to buildings through a mediator.
 */

#include "PowerPlant.h"
#include "Utility.h"
#include "UtilityMediator.h"
#include "ResourceType.h"

#include <iostream>

/**
 * @brief Constructor for PowerPlant.
 * @param mediator Pointer to the UtilityMediator.
 */
PowerPlant::PowerPlant(UtilityMediator* mediator) : Utility(mediator) {
    this->mediator = mediator;
}

/**
 * @brief Registers a building to receive power.
 * @param building Pointer to the building to be registered.
 */
void PowerPlant::registerBuilding(Building* building) {
    std::cout << "Building registered with PowerPlant.\n";
}

/**
 * @brief Supplies power to a building.
 * @param building Pointer to the building to receive power.
 */
void PowerPlant::supplyResources(Building* building) {
    // Request power from the mediator and supply to the building
    if (this->mediator->requestResources(ResourceType::Power, 50)) {
        std::cout << "Power supplied to building.\n";
    } else {
        std::cout << "Insufficient power to supply to building.\n";
    }
}

/**
 * @brief Generates electricity for a building.
 * @param building Pointer to the building to receive electricity.
 */
void PowerPlant::generateElectricity(Building* building) {
    // TODO - implement PowerPlant::generateElectricity
    throw "Not yet implemented";
}

/**
 * @brief Supplies power to a building.
 * @param building Pointer to the building to receive power.
 */
void PowerPlant::supplyPower(Building* building) {
    // TODO - implement PowerPlant::supplyPower
    throw "Not yet implemented";
}

/**
 * @brief Default constructor for PowerPlant.
 */
PowerPlant::PowerPlant() {
    // TODO - implement PowerPlant::PowerPlant
    throw "Not yet implemented";
}