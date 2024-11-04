// Observer.h
#ifndef OBSERVER_H
#define OBSERVER_H

#include "ResourceType.h"

class Observer {
public:
    virtual void update(ResourceType type, int quantity) = 0;
};

#endif
