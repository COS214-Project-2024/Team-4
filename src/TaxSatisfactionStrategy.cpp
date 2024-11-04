/**
 * @file TaxSatisfactionStrategy.cpp
 * @brief Implementation of the TaxSatisfactionStrategy class.
 * 
 * This file contains the implementation of the TaxSatisfactionStrategy class, 
 * which calculates and updates the satisfaction level of a citizen based on tax rates.
 * 
 * @version 1.0
 * @date 2023-10-05
 * 
 */

#include "TaxSatisfactionStrategy.h"
#include "Citizen.h"

/**
 * @brief Calculates the satisfaction level of a citizen based on the tax rate.
 * 
 * This function calculates the satisfaction level of a citizen by reducing their 
 * current satisfaction level based on the tax rate. Higher tax rates result in 
 * lower satisfaction levels.
 * 
 * @param citizen The citizen whose satisfaction level is to be calculated.
 * @return The calculated satisfaction level.
 */
float TaxSatisfactionStrategy::calculateSatisfaction(const Citizen& citizen) {
    // Higher tax rate lowers satisfaction
    float taxImpact = citizen.getTaxRate() * 50.0f; // Scales impact based on tax rate
    return std::max(citizen.getSatisfactionLevel() - taxImpact, 0.0f);
}

/**
 * @brief Updates the satisfaction level of a citizen based on a tax change.
 * 
 * This function updates the satisfaction level of a citizen by applying a small 
 * impact based on the change in tax rate.
 * 
 * @param citizen The citizen whose satisfaction level is to be updated.
 */
void TaxSatisfactionStrategy::updateForTaxChange(Citizen& citizen) {
    float taxImpact = citizen.getTaxRate() * 10.0f; // Small impact per tax change
    citizen.updateSatisfaction(std::max(citizen.getSatisfactionLevel() - taxImpact, 0.0f));
}