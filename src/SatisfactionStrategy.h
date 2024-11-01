// SatisfactionStrategy.h

#ifndef SATISFACTION_STRATEGY_H
#define SATISFACTION_STRATEGY_H

class Citizen;

class SatisfactionStrategy {
public:
    virtual ~SatisfactionStrategy() = default;
    virtual float calculateSatisfaction(const Citizen& citizen) const = 0;
};

#endif // SATISFACTION_STRATEGY_H
