// JobSatisfactionStrategy.h

#ifndef JOB_SATISFACTION_STRATEGY_H
#define JOB_SATISFACTION_STRATEGY_H

#include "SatisfactionStrategy.h"

class JobSatisfactionStrategy : public SatisfactionStrategy {
public:
    float calculateSatisfaction(const Citizen& citizen) const override;
};

#endif // JOB_SATISFACTION_STRATEGY_H
