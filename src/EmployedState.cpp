/**
 * @file EmployedState.cpp
 * @brief Implementation of the EmployedState class for handling the employed state of a Citizen.
 * 
 * This file contains the implementation of the EmployedState class, which provides
 * methods to handle the state of a Citizen when they are employed.
 * 
 * @version 1.0
 * @date 2023-10-01
 */

#include "EmployedState.h"
#include "Citizen.h"

/**
 * @brief Clamps a value between a minimum and maximum.
 * 
 * This function ensures that the value stays within the specified range.
 * 
 * @param value The value to be clamped.
 * @param min The minimum value.
 * @param max The maximum value.
 * @return double The clamped value.
 */
double clamp(double value, double min, double max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

/**
 * @brief Handles the state of a Citizen when they are employed.
 * 
 * This method updates the satisfaction level of the Citizen when they are in the employed state.
 * 
 * @param citizen Reference to the Citizen object.
 */
void EmployedState::handleState(Citizen& citizen) const {
    double newSatisfaction = clamp(citizen.getSatisfactionLevel() + 10.0, 0.0, 100.0);
    citizen.setSatisfactionLevel(newSatisfaction);  // Use this if setSatisfactionLevel is added
    citizen.updateSatisfaction(); // Calls the no-parameter update
}