#ifndef TAXSATISFACTIONSTRATEGY_H
#define TAXSATISFACTIONSTRATEGY_H

#include "SatisfactionStrategy.h"

/**
 * @class TaxSatisfactionStrategy
 * @brief A strategy for calculating and updating citizen satisfaction based on tax rates.
 * 
 * This class provides methods to calculate and update the satisfaction level of a citizen 
 * based on the current tax rate. It inherits from the SatisfactionStrategy interface.
 * 
 * @version 1.0
 * @date 2024-11-04
 */
class TaxSatisfactionStrategy : public SatisfactionStrategy {
public:
    /**
     * @brief Calculates the satisfaction level of a citizen based on the tax rate.
     * 
     * @param citizen The citizen whose satisfaction level is to be calculated.
     * @return The calculated satisfaction level.
     */
    float calculateSatisfaction(const Citizen& citizen) override;

    /**
     * @brief Updates the satisfaction level of a citizen based on a job change.
     * 
     * This method is currently not implemented.
     * 
     * @param citizen The citizen whose satisfaction level is to be updated.
     */
    void updateForJobChange(Citizen& citizen) override {}

    /**
     * @brief Updates the satisfaction level of a citizen based on a housing change.
     * 
     * This method is currently not implemented.
     * 
     * @param citizen The citizen whose satisfaction level is to be updated.
     */
    void updateForHousingChange(Citizen& citizen) override {}

    /**
     * @brief Updates the satisfaction level of a citizen based on a tax change.
     * 
     * @param citizen The citizen whose satisfaction level is to be updated.
     */
    void updateForTaxChange(Citizen& citizen) override;
};

#endif // TAXSATISFACTIONSTRATEGY_H