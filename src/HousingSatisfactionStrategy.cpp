/**
 * @file HousingSatisfactionStrategy.cpp
 * @brief Implementation of the HousingSatisfactionStrategy class.
 * @version 1.0
 * @date 2024-11-04
 * This file contains the implementation of the HousingSatisfactionStrategy class, which provides
 * methods to calculate and update citizen satisfaction based on housing conditions.
 */

#include "HousingSatisfactionStrategy.h"
#include "Citizen.h"

/**
 * @brief Calculates the satisfaction level of a citizen based on housing conditions.
 * @param citizen The citizen whose satisfaction level is to be calculated.
 * @return The calculated satisfaction level.
 */
float HousingSatisfactionStrategy::calculateSatisfaction(const Citizen& citizen) {
    return std::min(citizen.getSatisfactionLevel() + 7.0f, 100.0f); // Adjust for housing quality
}

/**
 * @brief Updates the satisfaction level of a citizen due to a change in housing conditions.
 * @param citizen The citizen whose satisfaction level is to be updated.
 */
void HousingSatisfactionStrategy::updateForHousingChange(Citizen& citizen) {
    citizen.updateSatisfaction(std::min(citizen.getSatisfactionLevel() + 3.0f, 100.0f)); // Small increase on housing upgrade
}