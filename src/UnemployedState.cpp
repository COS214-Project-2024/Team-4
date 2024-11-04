/**
 * @file UnemployedState.cpp
 * @brief Implementation of the UnemployedState class.
 * 
 * This file contains the implementation of the UnemployedState class, which handles the behavior of a citizen in an unemployed state.
 * 
 * @version 1.0
 * @date 2023-10-05
 * 
 * @note This file is part of a larger project that simulates the behavior of citizens in various states.
 */

#include "UnemployedState.h"
#include "Citizen.h"

/**
 * @brief Handles the state-specific behavior for an unemployed citizen.
 * 
 * This function decreases the satisfaction level of a citizen due to unemployment.
 * The satisfaction level is clamped between 0.0 and 100.0.
 * 
 * @param citizen The citizen whose state is being handled.
 */
void UnemployedState::handleState(Citizen& citizen) const {
    // Decrease satisfaction due to unemployment
    double newSatisfaction = std::clamp(citizen.getSatisfactionLevel() - 10.0, 0.0, 100.0);
    citizen.setSatisfactionLevel(newSatisfaction);  // Use this if setSatisfactionLevel is added
}