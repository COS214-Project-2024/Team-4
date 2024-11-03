#ifndef SATISFACTIONSTRATEGY_H
#define SATISFACTIONSTRATEGY_H

#include "Citizen.h"

class SatisfactionStrategy {
public:
    virtual ~SatisfactionStrategy() = default;

    virtual float calculateSatisfaction(const Citizen& citizen) = 0;
    virtual void updateForJobChange(Citizen& citizen) = 0;
    virtual void updateForHousingChange(Citizen& citizen) = 0;
    virtual void updateForTaxChange(Citizen& citizen) = 0;
};

#endif


