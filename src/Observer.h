/**
 * @file Observer.h
 * @brief Definition of the Observer class.
 * @version 1.0
 * 
 * This file contains the definition of the Observer class, which provides an interface for
 * objects that need to be notified of changes in resource types and quantities.
 */

#ifndef OBSERVER_H
#define OBSERVER_H

#include "ResourceType.h"

/**
 * @class Observer
 * @brief Interface for objects that need to be notified of changes in resource types and quantities.
 * 
 * The Observer class provides an interface for objects that need to be notified of changes
 * in resource types and quantities.
 */
class Observer {
public:
    /**
     * @brief Updates the observer with the new resource type and quantity.
     * @param type The type of the resource.
     * @param quantity The quantity of the resource.
     */
    virtual void update(ResourceType type, int quantity) = 0;
};

#endif // OBSERVER_H