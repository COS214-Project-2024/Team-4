// ResourceManager.h
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "ResourceType.h"
#include "Observer.h"
#include "Resource.h"
#include "ResourceAllocationStrategy.h"
#include <map>
#include <vector>

class ResourceManager {
private:
    int budget;
    std::map<ResourceType, Resource*> resources;
    std::map<ResourceType, int> resourceCosts;
    ResourceAllocationStrategy* allocationStrategy;
    std::vector<Observer*> observers; // List of observers (like UtilityMediator)

public:
    ResourceManager(int initialBudget) : budget(initialBudget) {}

    bool allocateResources(ResourceType type, int quantity) {
        if (resources.count(type) && budget >= resourceCosts[type] * quantity && resources[type]->allocate(quantity)) {
            budget -= resourceCosts[type] * quantity;
            notifyObservers(type, quantity);
            return true;
        }
        return false;
    }

    void releaseResources(ResourceType type, int quantity) {
        if (resources.count(type)) {
            resources[type]->release(quantity);
            notifyObservers(type, -quantity);  // Negative to indicate release
        }
    }

    void setAllocationStrategy(ResourceAllocationStrategy* strategy) {
        allocationStrategy = strategy;
    }

    int getBudget() const { return budget; }

    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    Resource* getResource(ResourceType type) const {
        auto it = resources.find(type);
        return (it != resources.end()) ? it->second : nullptr;
    }

    // Method to add a resource to the manager
    void addResource(ResourceType type, Resource* resource) {
        if (resources.count(type) == 0) {
            resources[type] = resource;
        }
    }

private:
    void notifyObservers(ResourceType type, int quantity) {
        for (auto obs : observers) {
            obs->update(type, quantity);
        }
    }
};

#endif // RESOURCEMANAGER_H
