/**
 * @file ResourceAllocationStrategy.h
 * @brief Header file for resource allocation strategy classes.
 * 
 * This file contains the definition of the ResourceAllocationStrategy interface and its 
 * derived classes, which provide different strategies for allocating resources.
 * 
 * @version 1.0
 * @date 2024-11-04
 */

#ifndef RESOURCEALLOCATIONSTRATEGY_H
#define RESOURCEALLOCATIONSTRATEGY_H

#include "ResourceType.h"

/**
 * @class ResourceAllocationStrategy
 * @brief Interface for resource allocation strategies.
 * 
 * The ResourceAllocationStrategy class provides a pure virtual method for allocating resources.
 */
class ResourceAllocationStrategy {
public:
    /**
     * @brief Allocates a specified quantity of a resource type.
     * 
     * @param type The type of the resource.
     * @param quantity The quantity of the resource to allocate.
     * @return True if the allocation was successful, false otherwise.
     */
    virtual bool allocate(ResourceType type, int quantity) = 0;
};

/**
 * @class PriorityDistributionStrategy
 * @brief Strategy for priority-based resource allocation.
 * 
 * The PriorityDistributionStrategy class implements the ResourceAllocationStrategy interface 
 * and provides logic for priority-based allocation of resources.
 */
class PriorityDistributionStrategy : public ResourceAllocationStrategy {
public:
    /**
     * @brief Allocates resources based on priority.
     * 
     * @param type The type of the resource.
     * @param quantity The quantity of the resource to allocate.
     * @return True if the allocation was successful, false otherwise.
     */
    bool allocate(ResourceType type, int quantity) override {
        // Logic for priority-based allocation
        return true;
    }
};

/**
 * @class EqualDistributionStrategy
 * @brief Strategy for equal distribution of resources.
 * 
 * The EqualDistributionStrategy class implements the ResourceAllocationStrategy interface 
 * and provides logic for equal distribution of resources.
 */
class EqualDistributionStrategy : public ResourceAllocationStrategy {
public:
    /**
     * @brief Allocates resources equally.
     * 
     * @param type The type of the resource.
     * @param quantity The quantity of the resource to allocate.
     * @return True if the allocation was successful, false otherwise.
     */
    bool allocate(ResourceType type, int quantity) override {
        // Logic for equal distribution
        return true;
    }
};

#endif // RESOURCEALLOCATIONSTRATEGY_H