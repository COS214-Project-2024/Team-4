// ResourceManager.h
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "ResourceType.h"
#include <map>
#include <vector>
#include "Resource.h"
#include "ResourceAllocationStrategy.h"

class ResourceManager {
private:
    int budget;
    std::map<ResourceType, Resource*> resources;
    std::map<ResourceType, int> resourceCosts;
    ResourceAllocationStrategy* allocationStrategy;

public:
    ResourceManager(int initialBudget) : budget(initialBudget) {}

    bool allocateResources(ResourceType type, int quantity) {
        if (budget >= resourceCosts[type] * quantity && resources[type]->allocate(quantity)) {
            budget -= resourceCosts[type] * quantity;
            //notifyObservers();
            return true;
        }
        return false;
    }

    void releaseResources(ResourceType type, int quantity) {
        resources[type]->release(quantity);
        //notifyObservers();
    }

    void setAllocationStrategy(ResourceAllocationStrategy* strategy) {
        allocationStrategy = strategy;
    }

    int getBudget() const { return budget; }

// private:
//     void notifyObservers() {
//         for (auto obs : observers) obs->update();
//     }
};

#endif // RESOURCEMANAGER_H
