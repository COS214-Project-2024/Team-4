/**
 * @file UnsatisfiedState.h
 * @brief Declaration of the UnsatisfiedState class.
 * 
 * This file contains the declaration of the UnsatisfiedState class, which handles the behavior of a citizen in an unsatisfied state.
 * 
 * @version 1.0
 * @date 2024-11-04
 * 
 * @note This file is part of a larger project that simulates the behavior of citizens in various states.
 */

#ifndef UNSATISFIEDSTATE_H
#define UNSATISFIEDSTATE_H

#include "CitizenState.h"

/**
 * @class UnsatisfiedState
 * @brief A class that represents the unsatisfied state of a citizen.
 * 
 * The UnsatisfiedState class is responsible for handling the behavior of a citizen when they are unsatisfied.
 */
class UnsatisfiedState : public CitizenState {
public:
    /**
     * @brief Handles the state-specific behavior for an unsatisfied citizen.
     * 
     * This function decreases the satisfaction level of a citizen due to dissatisfaction.
     * The satisfaction level is clamped between 0.0 and 100.0.
     * 
     * @param citizen The citizen whose state is being handled.
     */
    void handleState(Citizen& citizen) const override;
};

#endif // UNSATISFIEDSTATE_H