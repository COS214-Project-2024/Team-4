
// HousingSatisfactionStrategy.h

#ifndef HOUSINGSATISFACTIONSTRATEGY_H
#define HOUSINGSATISFACTIONSTRATEGY_H

#include "SatisfactionStrategy.h"
#include "Citizen.h"

class HousingSatisfactionStrategy : public SatisfactionStrategy {
public:
    float calculateSatisfaction(const Citizen& citizen) const override;
};

#endif // HOUSINGSATISFACTIONSTRATEGY_H
