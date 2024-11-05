/**
 * @file JobSatisfactionStrategy.h
 * @brief Definition of the JobSatisfactionStrategy class.
 * @version 1.0
 * @date 2024-11-04
 * This file contains the definition of the JobSatisfactionStrategy class, which provides
 * methods to calculate and update citizen satisfaction based on job conditions.
 */

#ifndef JOBSATISFACTIONSTRATEGY_H
#define JOBSATISFACTIONSTRATEGY_H

#include "SatisfactionStrategy.h"

/**
 * @class JobSatisfactionStrategy
 * @brief Strategy for calculating and updating citizen satisfaction based on job conditions.
 * 
 * The JobSatisfactionStrategy class provides methods to calculate and update citizen satisfaction
 * based on job conditions.
 */
class JobSatisfactionStrategy : public SatisfactionStrategy {
public:
    /**
     * @brief Calculates the satisfaction level of a citizen based on job conditions.
     * @param citizen The citizen whose satisfaction level is to be calculated.
     * @return The calculated satisfaction level.
     */
    float calculateSatisfaction(const Citizen& citizen) override;

    /**
     * @brief Updates the satisfaction level of a citizen due to a change in job conditions.
     * @param citizen The citizen whose satisfaction level is to be updated.
     */
    void updateForJobChange(Citizen& citizen) override;

    /**
     * @brief Updates the satisfaction level of a citizen due to a change in housing conditions.
     * 
     * This method is not implemented for job satisfaction strategy.
     * @param citizen The citizen whose satisfaction level is to be updated.
     */
    void updateForHousingChange(Citizen& citizen) override {}

    /**
     * @brief Updates the satisfaction level of a citizen due to a change in tax conditions.
     * 
     * This method is not implemented for job satisfaction strategy.
     * @param citizen The citizen whose satisfaction level is to be updated.
     */
    void updateForTaxChange(Citizen& citizen) override {}
};

#endif // JOBSATISFACTIONSTRATEGY_H