/**
 * @file UtilityMediator.cpp
 * @brief Implementation of the UtilityMediator class.
 * 
 * This file contains the implementation of the UtilityMediator class, which manages resource distribution for utilities.
 * 
 * @version 1.0
 * @date 2024-11-04
 * 
 * @note This file is part of a larger project that simulates the behavior of citizens and buildings in a city.
 */

#include "UtilityMediator.h"

/**
 * @brief Requests resources from the mediator.
 * 
 * This function checks if the requested amount of resources is available and, if so, deducts it from the inventory.
 * 
 * @param type The type of resource being requested.
 * @param amount The amount of resource being requested.
 * @return true if the request is fulfilled, false otherwise.
 */
bool UtilityMediator::requestResources(ResourceType type, int amount) {
    if (resourceInventory[type] >= amount) {
        resourceInventory[type] -= amount;
        return true;  // Request fulfilled
    }
    return false;  // Insufficient resources
}

/**
 * @brief Releases resources back to the mediator.
 * 
 * This function adds the specified amount of resources back to the inventory.
 * 
 * @param type The type of resource being released.
 * @param amount The amount of resource being released.
 */
void UtilityMediator::releaseResources(ResourceType type, int amount) {
    resourceInventory[type] += amount;
}

/**
 * @brief Produces resources for the mediator.
 * 
 * This function adds the specified amount of resources to the inventory.
 * 
 * @param type The type of resource being produced.
 * @param amount The amount of resource being produced.
 */
void UtilityMediator::produceResource(ResourceType type, int amount) {
    resourceInventory[type] += amount;
}

/**
 * @brief Gets the available amount of a specific resource.
 * 
 * This function returns the amount of the specified resource available in the inventory.
 * 
 * @param type The type of resource being queried.
 * @return The amount of the specified resource available.
 */
int UtilityMediator::getAvailableResource(ResourceType type) const {
    return resourceInventory.count(type) ? resourceInventory.at(type) : 0;
}

/**
 * @brief Updates the inventory with a specified quantity of a resource.
 * 
 * This function adds the specified quantity of a resource to the inventory.
 * 
 * @param type The type of resource being updated.
 * @param quantity The quantity of the resource being added.
 */
void UtilityMediator::update(ResourceType type, int quantity) {
    resourceInventory[type] += quantity;
}