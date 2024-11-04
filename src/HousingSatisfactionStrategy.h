/**
 * @file HousingSatisfactionStrategy.h
 * @brief Definition of the HousingSatisfactionStrategy class.
 * @version 1.0
 * @date 2024-11-04
 * This file contains the definition of the HousingSatisfactionStrategy class, which provides
 * methods to calculate and update citizen satisfaction based on housing conditions.
 */

#ifndef HOUSINGSATISFACTIONSTRATEGY_H
#define HOUSINGSATISFACTIONSTRATEGY_H

#include "SatisfactionStrategy.h"

/**
 * @class HousingSatisfactionStrategy
 * @brief Strategy for calculating and updating citizen satisfaction based on housing conditions.
 * 
 * The HousingSatisfactionStrategy class provides methods to calculate and update citizen satisfaction
 * based on housing conditions.
 */
class HousingSatisfactionStrategy : public SatisfactionStrategy {
public:
    /**
     * @brief Calculates the satisfaction level of a citizen based on housing conditions.
     * @param citizen The citizen whose satisfaction level is to be calculated.
     * @return The calculated satisfaction level.
     */
    float calculateSatisfaction(const Citizen& citizen) override;

    /**
     * @brief Updates the satisfaction level of a citizen due to a change in housing conditions.
     * @param citizen The citizen whose satisfaction level is to be updated.
     */
    void updateForHousingChange(Citizen& citizen) override;

    /**
     * @brief Updates the satisfaction level of a citizen due to a change in job conditions.
     * 
     * This method is not implemented for housing satisfaction strategy.
     * @param citizen The citizen whose satisfaction level is to be updated.
     */
    void updateForJobChange(Citizen& citizen) override {}

    /**
     * @brief Updates the satisfaction level of a citizen due to a change in tax conditions.
     * 
     * This method is not implemented for housing satisfaction strategy.
     * @param citizen The citizen whose satisfaction level is to be updated.
     */
    void updateForTaxChange(Citizen& citizen) override {}
};

#endif // HOUSINGSATISFACTIONSTRATEGY_H