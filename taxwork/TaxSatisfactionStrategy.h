// TaxSatisfactionStrategy.h

#ifndef TAXSATISFACTIONSTRATEGY_H
#define TAXSATISFACTIONSTRATEGY_H

#include "SatisfactionStrategy.h"
#include "Citizen.h"

class TaxSatisfactionStrategy : public SatisfactionStrategy {
public:
    float calculateSatisfaction(const Citizen& citizen) const override;
};

#endif // TAXSATISFACTIONSTRATEGY_H