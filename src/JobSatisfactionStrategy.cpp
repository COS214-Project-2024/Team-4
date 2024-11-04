/**
 * @file JobSatisfactionStrategy.cpp
 * @brief Implementation of the JobSatisfactionStrategy class.
 * @version 1.0
 * 
 * This file contains the implementation of the JobSatisfactionStrategy class, which provides
 * methods to calculate and update citizen satisfaction based on job conditions.
 */

#include "JobSatisfactionStrategy.h"
#include "Citizen.h"

/**
 * @brief Calculates the satisfaction level of a citizen based on job conditions.
 * @param citizen The citizen whose satisfaction level is to be calculated.
 * @return The calculated satisfaction level.
 */
float JobSatisfactionStrategy::calculateSatisfaction(const Citizen& citizen) {
    if (citizen.isEmployed()) {
        return std::min(citizen.getSatisfactionLevel() + 10.0f, 100.0f); // Increase if employed
    } else {
        return std::max(citizen.getSatisfactionLevel() - 30.0f, 0.0f); // Decrease if unemployed
    }
}

/**
 * @brief Updates the satisfaction level of a citizen due to a change in job conditions.
 * @param citizen The citizen whose satisfaction level is to be updated.
 */
void JobSatisfactionStrategy::updateForJobChange(Citizen& citizen) {
    if (citizen.isEmployed()) {
        citizen.updateSatisfaction(std::min(citizen.getSatisfactionLevel() + 5.0f, 100.0f)); // Small increase on job change
    } else {
        citizen.updateSatisfaction(std::max(citizen.getSatisfactionLevel() - 30.0f, 0.0f)); // Decrease on job loss
    }
}
