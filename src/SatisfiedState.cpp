/**
 * @file SatisfiedState.cpp
 * @brief Implementation file for the SatisfiedState class.
 * 
 * This file contains the implementation of the SatisfiedState class, which 
 * represents a state where a citizen is satisfied. It provides methods to 
 * handle the state and update the citizen's satisfaction level.
 * 
 * @version 1.0
 * @date 2024-11-04
 */

#include "SatisfiedState.h"
#include "Citizen.h"

/**
 * @brief Handles the satisfied state for a citizen.
 * 
 * @param citizen The citizen whose state is being handled.
 */
void SatisfiedState::handleState(Citizen& citizen) const {
    // Maintain or slightly boost satisfaction
    citizen.updateSatisfaction(citizen.getSatisfactionLevel() + 2.0);
}