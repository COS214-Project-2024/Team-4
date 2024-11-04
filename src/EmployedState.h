/**
 * @file EmployedState.h
 * @brief Declaration of the EmployedState class for handling the employed state of a Citizen.
 * 
 * This file contains the declaration of the EmployedState class, which provides
 * methods to handle the state of a Citizen when they are employed.
 * 
 * @version 1.0
 * @date 2024-11-04
 */

#ifndef EMPLOYEDSTATE_H
#define EMPLOYEDSTATE_H

#include "CitizenState.h"

/**
 * @class EmployedState
 * @brief The EmployedState class for handling the employed state of a Citizen.
 * 
 * This class provides methods to handle the state of a Citizen when they are employed.
 */
class EmployedState : public CitizenState {
public:
    /**
     * @brief Handles the state of a Citizen when they are employed.
     * 
     * This method updates the satisfaction level of the Citizen when they are in the employed state.
     * 
     * @param citizen Reference to the Citizen object.
     */
    void handleState(Citizen& citizen) const override;
};

#endif // EMPLOYEDSTATE_H