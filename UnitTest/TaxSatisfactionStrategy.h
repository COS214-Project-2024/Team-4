#ifndef TAXSATISFACTIONSTRATEGY_H
#define TAXSATISFACTIONSTRATEGY_H

#include "SatisfactionStrategy.h"

class TaxSatisfactionStrategy : public SatisfactionStrategy {
public:
    float calculateSatisfaction(const Citizen& citizen) override;
    void updateForJobChange(Citizen& citizen) override {}
    void updateForHousingChange(Citizen& citizen) override {}
    void updateForTaxChange(Citizen& citizen) override;
};

#endif




