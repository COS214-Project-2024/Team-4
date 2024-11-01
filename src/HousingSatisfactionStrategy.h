// HousingSatisfactionStrategy.h

#ifndef HOUSING_SATISFACTION_STRATEGY_H
#define HOUSING_SATISFACTION_STRATEGY_H

#include "SatisfactionStrategy.h"

class HousingSatisfactionStrategy : public SatisfactionStrategy {
public:
    float calculateSatisfaction(const Citizen& citizen) const override;
};

#endif // HOUSING_SATISFACTION_STRATEGY_H
