/**
 * @file CitizenSatisfactionObserver.h
 * @brief Header file for the CitizenSatisfactionObserver class.
 * 
 * This file contains the declaration of the CitizenSatisfactionObserver class, which observes changes
 * in citizen satisfaction and updates their state accordingly.
 * 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @note This file is part of a project for managing city citizens and their properties.
 */

#ifndef CITIZEN_SATISFACTION_OBSERVER_H
#define CITIZEN_SATISFACTION_OBSERVER_H

#include "CitizenObserver.h"
#include "Citizen.h"
#include <iostream>

/**
 * @class CitizenSatisfactionObserver
 * @brief Observes changes in citizen satisfaction and updates their state accordingly.
 * 
 * This class implements the CitizenObserver interface and observes changes in citizen satisfaction,
 * updating their state based on the new satisfaction level.
 */
class CitizenSatisfactionObserver : public CitizenObserver {
public:
    /**
     * @brief Updates the satisfaction and state of the observed citizen.
     * 
     * @param citizen Pointer to the Citizen object that has changed.
     */
    void update(Citizen* citizen) override {
        // Adjust satisfaction and update state based on conditions
        citizen->updateSatisfaction(); // Update satisfaction
        citizen->checkAndUpdateState(); // Check and update state if necessary

        std::cout << citizen->getName() << "'s satisfaction updated to "
                  << citizen->getSatisfactionLevel() << "%, state updated.\n";
    }
};

#endif // CITIZEN_SATISFACTION_OBSERVER_H