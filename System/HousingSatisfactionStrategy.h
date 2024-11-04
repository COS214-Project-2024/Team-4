#ifndef HOUSINGSATISFACTIONSTRATEGY_H
#define HOUSINGSATISFACTIONSTRATEGY_H

#include "SatisfactionStrategy.h"

class HousingSatisfactionStrategy : public SatisfactionStrategy {
public:
    float calculateSatisfaction(const Citizen& citizen) override;
    void updateForJobChange(Citizen& citizen) override {}
    void updateForHousingChange(Citizen& citizen) override;
    void updateForTaxChange(Citizen& citizen) override {}
};

#endif



