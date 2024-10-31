// ResourceAllocationStrategy.h
#ifndef RESOURCEALLOCATIONSTRATEGY_H
#define RESOURCEALLOCATIONSTRATEGY_H

#include "ResourceType.h"

class ResourceAllocationStrategy {
public:
    virtual bool allocate(ResourceType type, int quantity) = 0;
};

class PriorityDistributionStrategy : public ResourceAllocationStrategy {
public:
    bool allocate(ResourceType type, int quantity) override {
        // Logic for priority-based allocation
        return true;
    }
};

class EqualDistributionStrategy : public ResourceAllocationStrategy {
public:
    bool allocate(ResourceType type, int quantity) override {
        // Logic for equal distribution
        return true;
    }
};

#endif // RESOURCEALLOCATIONSTRATEGY_H
