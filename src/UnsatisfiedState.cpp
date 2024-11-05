/**
 * @file UnsatisfiedState.cpp
 * @brief Implementation of the UnsatisfiedState class.
 * 
 * This file contains the implementation of the UnsatisfiedState class, which handles the behavior of a citizen in an unsatisfied state.
 * 
 * @version 1.0
 * @date 2024-11-04
 * 
 * @note This file is part of a larger project that simulates the behavior of citizens in various states.
 */

#include "UnsatisfiedState.h"
#include "Citizen.h"
#include <algorithm>

/**
 * @brief Handles the state-specific behavior for an unsatisfied citizen.
 * 
 * This function decreases the satisfaction level of a citizen due to dissatisfaction.
 * The satisfaction level is clamped between 0.0 and 100.0.
 * 
 * @param citizen The citizen whose state is being handled.
 */
void UnsatisfiedState::handleState(Citizen& citizen) const {
    // Lower satisfaction
    double newSatisfaction = std::clamp(citizen.getSatisfactionLevel() - 50.0, 0.0, 100.0);
    citizen.setSatisfactionLevel(newSatisfaction);  // Use this if setSatisfactionLevel is added
}