/**
 * @file SewageManagement.cpp
 * @brief Implementation of the SewageManagement class.
 * 
 * This file contains the implementation of the SewageManagement class, which manages sewage services for buildings.
 * 
 * @version 1.0
 * @date 2023-10-05
 * 
 */

#include "SewageManagement.h"
#include <iostream>

/**
 * @brief Constructor for SewageManagement.
 * 
 * Initializes the sewage management service with the given utility mediator.
 * 
 * @param mediator Pointer to the UtilityMediator object.
 */
SewageManagement::SewageManagement(UtilityMediator* mediator) : Utility(mediator) {}

/**
 * @brief Registers a building with the sewage management service.
 * 
 * @param building Pointer to the Building object to be registered.
 */
void SewageManagement::registerBuilding(Building* building) {
    std::cout << "Building registered with SewageManagement.\n";
}

/**
 * @brief Supplies sewage management services to a building.
 * 
 * Requests resources from the mediator and provides sewage management services if resources are available.
 * 
 * @param building Pointer to the Building object to receive services.
 */
void SewageManagement::supplyResources(Building* building) {
    if (mediator->requestResources(ResourceType::Sewage, 20)) {
        std::cout << "Sewage management service provided to building.\n";
    } else {
        std::cout << "Insufficient sewage capacity for building.\n";
    }
}

// /**
//  * @brief Adjusts sewage management based on a citizen's requirements.
//  * 
//  * @param citizen Pointer to the Citizen object.
//  */
// void SewageManagement::adjustForCitizen(Citizen* citizen) {
//     std::cout << "Adjusting sewage management based on citizen's requirements.\n";
// }