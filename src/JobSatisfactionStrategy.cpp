// JobSatisfactionStrategy.cpp

#include "JobSatisfactionStrategy.h"
#include "Citizen.h"

float JobSatisfactionStrategy::calculateSatisfaction(const Citizen& citizen) const {
    // Example: Employed citizens are more satisfied than unemployed
    return citizen.isEmployed() ? 80.0f : 30.0f;
}
