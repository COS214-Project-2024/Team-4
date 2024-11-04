/**
 * @file UtilityMediator.h
 * @brief Declaration of the UtilityMediator class.
 * 
 * This file contains the declaration of the UtilityMediator class, which manages resource distribution for utilities.
 * 
 * @version 1.0
 * @date 2024-11-04
 * 
 * @note This file is part of a larger project that simulates the behavior of citizens and buildings in a city.
 */

#ifndef UTILITYMEDIATOR_H
#define UTILITYMEDIATOR_H

#include "ResourceType.h"
#include "Observer.h"
#include <map>

/**
 * @class UtilityMediator
 * @brief A class that manages resource distribution for utilities.
 * 
 * The UtilityMediator class is responsible for managing the inventory and distribution of resources for various utilities.
 */
class UtilityMediator : public Observer {
private:
    std::map<ResourceType, int> resourceInventory; ///< Inventory of resources managed by the mediator

public:
    /**
     * @brief Default constructor for the UtilityMediator class.
     */
    UtilityMediator() = default;

    /**
     * @brief Requests resources from the mediator.
     * 
     * This function checks if the requested amount of resources is available and, if so, deducts it from the inventory.
     * 
     * @param type The type of resource being requested.
     * @param amount The amount of resource being requested.
     * @return true if the request is fulfilled, false otherwise.
     */
    bool requestResources(ResourceType type, int amount);

    /**
     * @brief Releases resources back to the mediator.
     * 
     * This function adds the specified amount of resources back to the inventory.
     * 
     * @param type The type of resource being released.
     * @param amount The amount of resource being released.
     */
    void releaseResources(ResourceType type, int amount);

    /**
     * @brief Produces resources for the mediator.
     * 
     * This function adds the specified amount of resources to the inventory.
     * 
     * @param type The type of resource being produced.
     * @param amount The amount of resource being produced.
     */
    void produceResource(ResourceType type, int amount);

    /**
     * @brief Gets the available amount of a specific resource.
     * 
     * This function returns the amount of the specified resource available in the inventory.
     * 
     * @param type The type of resource being queried.
     * @return The amount of the specified resource available.
     */
    int getAvailableResource(ResourceType type) const;

    /**
     * @brief Updates the inventory with a specified quantity of a resource.
     * 
     * This function adds the specified quantity of a resource to the inventory.
     * 
     * @param type The type of resource being updated.
     * @param quantity The quantity of the resource being added.
     */
    void update(ResourceType type, int quantity) override;
};

#endif // UTILITYMEDIATOR_H