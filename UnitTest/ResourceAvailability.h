// ResourceAvailability.h
#ifndef RESOURCEAVAILABILITY_H
#define RESOURCEAVAILABILITY_H

#include "ResourceType.h"
#include "ResourceManager.h"

class ResourceAvailability {
private:
    ResourceManager* resourceManager;

public:
    ResourceAvailability(ResourceManager* manager) : resourceManager(manager) {}

    // Checks if a given quantity of a specific resource type is available
    bool checkAvailability(ResourceType type, int quantity) const {
        Resource* resource = resourceManager->getResource(type);
        if (resource) {
            return resource->getQuantity() >= quantity;
        }
        return false;  // Resource type not found
    }
};

#endif // RESOURCEAVAILABILITY_H
