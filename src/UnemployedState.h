/**
 * @file UnemployedState.h
 * @brief Declaration of the UnemployedState class.
 * 
 * This file contains the declaration of the UnemployedState class, which handles the behavior of a citizen in an unemployed state.
 * 
 * @version 1.0
 * @date 2023-10-05
 * 
 * @note This file is part of a larger project that simulates the behavior of citizens in various states.
 */

#ifndef UNEMPLOYEDSTATE_H
#define UNEMPLOYEDSTATE_H

#include "CitizenState.h"
#include <algorithm>
#include <iostream>

/**
 * @class UnemployedState
 * @brief A class that represents the unemployed state of a citizen.
 * 
 * The UnemployedState class is responsible for handling the behavior of a citizen when they are unemployed.
 */
class UnemployedState : public CitizenState {
public:
    /**
     * @brief Handles the state-specific behavior for an unemployed citizen.
     * 
     * This function decreases the satisfaction level of a citizen due to unemployment.
     * The satisfaction level is clamped between 0.0 and 100.0.
     * 
     * @param citizen The citizen whose state is being handled.
     */
    void handleState(Citizen& citizen) const override;
};

#endif // UNEMPLOYEDSTATE_H