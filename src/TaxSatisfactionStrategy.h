// TaxSatisfactionStrategy.h

#ifndef TAX_SATISFACTION_STRATEGY_H
#define TAX_SATISFACTION_STRATEGY_H

#include "SatisfactionStrategy.h"

class TaxSatisfactionStrategy : public SatisfactionStrategy {
public:
    float calculateSatisfaction(const Citizen& citizen) const override;
};

#endif // TAX_SATISFACTION_STRATEGY_H
