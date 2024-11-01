// SatisfactionStrategy.h

#ifndef SATISFACTIONSTRATEGY_H
#define SATISFACTIONSTRATEGY_H

class Citizen;  // Forward declaration

class SatisfactionStrategy {
public:
    virtual ~SatisfactionStrategy() = default;
    virtual float calculateSatisfaction(const Citizen& citizen) const = 0;
};

#endif // SATISFACTIONSTRATEGY_H

