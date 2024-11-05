/**
 * @file CitizenObserver.h
 * @brief Header file for the CitizenObserver class.
 * 
 * This file contains the declaration of the CitizenObserver class, which defines the interface
 * for observers that want to be notified of changes to Citizen objects.
 * 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @note This file is part of a project for managing city citizens and their properties.
 */

#ifndef CITIZEN_OBSERVER_H
#define CITIZEN_OBSERVER_H

class Citizen; // Forward declaration

/**
 * @class CitizenObserver
 * @brief Interface for observers of Citizen objects.
 * 
 * This class defines the interface for observers that want to be notified of changes to Citizen objects.
 */
class CitizenObserver {
public:
    /**
     * @brief Virtual destructor for the CitizenObserver class.
     */
    virtual ~CitizenObserver() = default;

    /**
     * @brief Abstract update method to be implemented by concrete observers.
     * 
     * @param citizen Pointer to the Citizen object that has changed.
     */
    virtual void update(Citizen* citizen) = 0;
};

#endif // CITIZEN_OBSERVER_H