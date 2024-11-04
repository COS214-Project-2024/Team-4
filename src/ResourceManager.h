/**
 * @file ResourceManager.h
 * @brief Header file for the ResourceManager class.
 * 
 * This file contains the definition of the ResourceManager class, which manages resources, 
 * handles resource allocation and release, and notifies observers about resource changes.
 * 
 * @version 1.0
 * @date 2024-11-04
 */

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "ResourceType.h"
#include "Observer.h"
#include "Resource.h"
#include "ResourceAllocationStrategy.h"
#include <map>
#include <vector>

/**
 * @class ResourceManager
 * @brief Manages resources, handles resource allocation and release, and notifies observers.
 * 
 * The ResourceManager class provides methods to allocate and release resources, set allocation 
 * strategies, manage budget, and notify observers about resource changes.
 */
class ResourceManager {
private:
    int budget; ///< The budget available for resource allocation.
    std::map<ResourceType, Resource*> resources; ///< Map of resource types to Resource objects.
    std::map<ResourceType, int> resourceCosts; ///< Map of resource types to their costs.
    ResourceAllocationStrategy* allocationStrategy; ///< Strategy for resource allocation.
    std::vector<Observer*> observers; ///< List of observers (like UtilityMediator).

public:
    /**
     * @brief Constructs a new ResourceManager object.
     * 
     * @param initialBudget The initial budget for the resource manager.
     */
    ResourceManager(int initialBudget) : budget(initialBudget) {}

    /**
     * @brief Allocates resources of a specific type and quantity.
     * 
     * @param type The type of the resource.
     * @param quantity The quantity of the resource to allocate.
     * @return True if the allocation was successful, false otherwise.
     */
    bool allocateResources(ResourceType type, int quantity) {
        if (resources.count(type) && budget >= resourceCosts[type] * quantity && resources[type]->allocate(quantity)) {
            budget -= resourceCosts[type] * quantity;
            notifyObservers(type, quantity);
            return true;
        }
        return false;
    }

    /**
     * @brief Releases resources of a specific type and quantity.
     * 
     * @param type The type of the resource.
     * @param quantity The quantity of the resource to release.
     */
    void releaseResources(ResourceType type, int quantity) {
        if (resources.count(type)) {
            resources[type]->release(quantity);
            notifyObservers(type, -quantity);  // Negative to indicate release
        }
    }

    /**
     * @brief Sets the resource allocation strategy.
     * 
     * @param strategy Pointer to the resource allocation strategy.
     */
    void setAllocationStrategy(ResourceAllocationStrategy* strategy) {
        allocationStrategy = strategy;
    }

    /**
     * @brief Gets the current budget.
     * 
     * @return The current budget.
     */
    int getBudget() const { return budget; }

    /**
     * @brief Adds an observer to the resource manager.
     * 
     * @param observer Pointer to the observer.
     */
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    /**
     * @brief Gets a resource of a specific type.
     * 
     * @param type The type of the resource.
     * @return Pointer to the Resource object, or nullptr if not found.
     */
    Resource* getResource(ResourceType type) const {
        auto it = resources.find(type);
        return (it != resources.end()) ? it->second : nullptr;
    }

    /**
     * @brief Adds a resource to the resource manager.
     * 
     * @param type The type of the resource.
     * @param resource Pointer to the Resource object.
     */
    void addResource(ResourceType type, Resource* resource) {
        if (resources.count(type) == 0) {
            resources[type] = resource;
        }
    }

private:
    /**
     * @brief Notifies observers about resource changes.
     * 
     * @param type The type of the resource.
     * @param quantity The quantity of the resource change.
     */
    void notifyObservers(ResourceType type, int quantity) {
        for (auto obs : observers) {
            obs->update(type, quantity);
        }
    }
};

#endif // RESOURCEMANAGER_H