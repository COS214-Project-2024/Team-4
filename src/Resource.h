/**
 * @file Resource.h
 * @brief Header file for the Resource class.
 * 
 * This file contains the definition of the Resource class, which represents a resource 
 * with a specific type and quantity. It provides methods to allocate and release the resource.
 * 
 * @version 1.0
 * @date 2023-10-05
 */

#ifndef RESOURCE_H
#define RESOURCE_H

#include "ResourceType.h"

/**
 * @class Resource
 * @brief Represents a resource with a specific type and quantity.
 * 
 * The Resource class provides methods to allocate and release the resource.
 */
class Resource {
private:
    ResourceType type; ///< The type of the resource.
    int quantity; ///< The quantity of the resource.

public:
    /**
     * @brief Constructs a new Resource object.
     * 
     * @param resourceType The type of the resource.
     * @param initialQuantity The initial quantity of the resource.
     */
    Resource(ResourceType resourceType, int initialQuantity)
        : type(resourceType), quantity(initialQuantity) {}

    /**
     * @brief Allocates a specified amount of the resource.
     * 
     * @param amount The amount to allocate.
     * @return True if the allocation was successful, false otherwise.
     */
    bool allocate(int amount) {
        if (quantity >= amount) {
            quantity -= amount;
            return true;
        }
        return false;
    }

    /**
     * @brief Releases a specified amount of the resource.
     * 
     * @param amount The amount to release.
     */
    void release(int amount) { quantity += amount; }
    
    /**
     * @brief Gets the type of the resource.
     * 
     * @return The type of the resource.
     */
    ResourceType getType() const { return type; }

    /**
     * @brief Gets the quantity of the resource.
     * 
     * @return The quantity of the resource.
     */
    int getQuantity() const { return quantity; }
};

#endif // RESOURCE_H