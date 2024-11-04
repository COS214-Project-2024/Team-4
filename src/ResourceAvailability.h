/**
 * @file ResourceAvailability.h
 * @brief Header file for the ResourceAvailability class.
 * 
 * This file contains the definition of the ResourceAvailability class, which 
 * checks the availability of a specific resource type and quantity.
 * 
 * @version 1.0
 * @date 2023-10-05
 */

#ifndef RESOURCEAVAILABILITY_H
#define RESOURCEAVAILABILITY_H

#include "ResourceType.h"
#include "ResourceManager.h"

/**
 * @class ResourceAvailability
 * @brief Checks the availability of a specific resource type and quantity.
 * 
 * The ResourceAvailability class provides a method to check if a given quantity 
 * of a specific resource type is available.
 */
class ResourceAvailability {
private:
    ResourceManager* resourceManager; ///< Pointer to the resource manager.

public:
    /**
     * @brief Constructs a new ResourceAvailability object.
     * 
     * @param manager Pointer to the resource manager.
     */
    ResourceAvailability(ResourceManager* manager) : resourceManager(manager) {}

    /**
     * @brief Checks if a given quantity of a specific resource type is available.
     * 
     * @param type The type of the resource.
     * @param quantity The quantity of the resource.
     * @return True if the resource is available, false otherwise.
     */
    bool checkAvailability(ResourceType type, int quantity) const {
        Resource* resource = resourceManager->getResource(type);
        if (resource) {
            return resource->getQuantity() >= quantity;
        }
        return false;  // Resource type not found
    }
};

#endif // RESOURCEAVAILABILITY_H