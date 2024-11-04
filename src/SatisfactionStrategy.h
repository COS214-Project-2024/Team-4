/**
 * @file SatisfactionStrategy.h
 * @brief Header file for the SatisfactionStrategy class.
 * 
 * This file contains the definition of the SatisfactionStrategy class, which 
 * provides an interface for calculating and updating citizen satisfaction based 
 * on various factors such as job, housing, and tax changes.
 * 
 * @version 1.0
 * @date 2024-11-04
 */

#ifndef SATISFACTIONSTRATEGY_H
#define SATISFACTIONSTRATEGY_H

#include "Citizen.h"

/**
 * @class SatisfactionStrategy
 * @brief Interface for calculating and updating citizen satisfaction.
 * 
 * The SatisfactionStrategy class provides methods to calculate citizen satisfaction 
 * and update it based on changes in job, housing, and taxes.
 */
class SatisfactionStrategy {
public:
    /**
     * @brief Virtual destructor for SatisfactionStrategy.
     */
    virtual ~SatisfactionStrategy() = default;

    /**
     * @brief Calculates the satisfaction of a citizen.
     * 
     * @param citizen The citizen whose satisfaction is to be calculated.
     * @return The calculated satisfaction level.
     */
    virtual float calculateSatisfaction(const Citizen& citizen) = 0;

    /**
     * @brief Updates the satisfaction of a citizen for a job change.
     * 
     * @param citizen The citizen whose satisfaction is to be updated.
     */
    virtual void updateForJobChange(Citizen& citizen) = 0;

    /**
     * @brief Updates the satisfaction of a citizen for a housing change.
     * 
     * @param citizen The citizen whose satisfaction is to be updated.
     */
    virtual void updateForHousingChange(Citizen& citizen) = 0;

    /**
     * @brief Updates the satisfaction of a citizen for a tax change.
     * 
     * @param citizen The citizen whose satisfaction is to be updated.
     */
    virtual void updateForTaxChange(Citizen& citizen) = 0;
};

#endif // SATISFACTIONSTRATEGY_H