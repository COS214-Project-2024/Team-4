// Resource.h
#ifndef RESOURCE_H
#define RESOURCE_H

#include "ResourceType.h"

class Resource {
private:
    ResourceType type;
    int quantity;

public:
    Resource(ResourceType resourceType, int initialQuantity)
        : type(resourceType), quantity(initialQuantity) {}

    bool allocate(int amount) {
        if (quantity >= amount) {
            quantity -= amount;
            return true;
        }
        return false;
    }

    void release(int amount) { quantity += amount; }
    
    ResourceType getType() const { return type; }
    int getQuantity() const { return quantity; }
};

#endif // RESOURCE_H
