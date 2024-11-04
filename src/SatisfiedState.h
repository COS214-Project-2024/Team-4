/**
 * @file SatisfiedState.h
 * @brief Header file for the SatisfiedState class.
 * 
 * This file contains the definition of the SatisfiedState class, which 
 * represents a state where a citizen is satisfied. It provides methods to 
 * handle the state and update the citizen's satisfaction level.
 * 
 * @version 1.0
 * @date 2023-10-05
 */

#ifndef SATISFIEDSTATE_H
#define SATISFIEDSTATE_H

#include "CitizenState.h"

/**
 * @class SatisfiedState
 * @brief Represents a state where a citizen is satisfied.
 * 
 * The SatisfiedState class provides methods to handle the state and update 
 * the citizen's satisfaction level.
 */
class SatisfiedState : public CitizenState {
public:
    /**
     * @brief Handles the satisfied state for a citizen.
     * 
     * @param citizen The citizen whose state is being handled.
     */
    void handleState(Citizen& citizen) const override;
};

#endif // SATISFIEDSTATE_H