// JobSatisfactionStrategy.h

#ifndef JOBSATISFACTIONSTRATEGY_H
#define JOBSATISFACTIONSTRATEGY_H

#include "SatisfactionStrategy.h"
#include "Citizen.h"

class JobSatisfactionStrategy : public SatisfactionStrategy {
public:
    float calculateSatisfaction(const Citizen& citizen) const override;
};

#endif // JOBSATISFACTIONSTRATEGY_H
