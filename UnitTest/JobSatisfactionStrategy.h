#ifndef JOBSATISFACTIONSTRATEGY_H
#define JOBSATISFACTIONSTRATEGY_H

#include "SatisfactionStrategy.h"

class JobSatisfactionStrategy : public SatisfactionStrategy {
public:
    float calculateSatisfaction(const Citizen& citizen) override;
    void updateForJobChange(Citizen& citizen) override;
    void updateForHousingChange(Citizen& citizen) override {}
    void updateForTaxChange(Citizen& citizen) override {}
};

#endif



