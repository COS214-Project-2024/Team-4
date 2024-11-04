#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "ResourceType.h"
#include "Observer.h"
#include "Resource.h"
#include "ResourceAllocationStrategy.h"
#include <map>
#include <vector>
#include <string>

class ResourceManager {
private:
    int budget;
    std::map<ResourceType, Resource*> resources;
    std::map<ResourceType, int> resourceCosts;  // Cost per unit for each resource type
    ResourceAllocationStrategy* allocationStrategy;
    std::vector<Observer*> observers; // List of observers (like UtilityMediator)

public:
    ResourceManager(int initialBudget) : budget(initialBudget), allocationStrategy(nullptr) {}

    bool allocateResources(ResourceType type, int quantity) {
        if (resources.count(type) && budget >= resourceCosts[type] * quantity) {
            if (resources[type]->allocate(quantity)) {  // Attempt allocation
                budget -= resourceCosts[type] * quantity;
                notifyObservers(type, quantity);
                return true;
            }
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

    // Method to add a resource with its cost per unit
    void addResource(ResourceType type, Resource* resource, int costPerUnit) {
        if (resources.count(type) == 0) {
            resources[type] = resource;
            resourceCosts[type] = costPerUnit;
        }
    }

    // Method to allocate a specific budget amount for a service
    bool allocateBudget(const std::string& serviceName, int amount) {
        if (amount > 0 && amount <= budget) {
            budget -= amount;
            std::cout << "Allocated " << amount << " for " << serviceName << ". Remaining budget: " << budget << "\n";
            return true;
        }
        std::cout << "Failed to allocate budget for " << serviceName << ". Insufficient funds or invalid amount.\n";
        return false;
    }

private:
    void notifyObservers(ResourceType type, int quantity) {
        for (auto obs : observers) {
            obs->update(type, quantity);
        }
    }
};

#endif // RESOURCEMANAGER_H
