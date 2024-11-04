/**
 * @file LeavingCityState.cpp
 * @brief Implementation of the LeavingCityState class.
 * @version 1.0
 * 
 * This file contains the implementation of the LeavingCityState class, which handles the state
 * of a citizen preparing to leave the city.
 */

#include "LeavingCityState.h"
#include "Citizen.h"

/**
 * @brief Handles the state of a citizen preparing to leave the city.
 * @param citizen The citizen whose state is being handled.
 * 
 * This method drastically reduces the satisfaction level of the citizen as they prepare to leave.
 */
void LeavingCityState::handleState(Citizen& citizen) const {
    // Drastically reduce satisfaction as citizen prepares to leave
    citizen.updateSatisfaction(citizen.getSatisfactionLevel() - 100.0);
}