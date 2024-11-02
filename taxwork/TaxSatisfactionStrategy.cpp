#include "TaxSatisfactionStrategy.h"
#include <algorithm> 

float TaxSatisfactionStrategy::calculateSatisfaction(const Citizen& citizen) const {
    // Calculate satisfaction based on the tax rate
    float maxSatisfaction = 100.0f;
    double taxRate = citizen.getTaxRate();
    float taxImpact = static_cast<float>(taxRate * 50.0); // Adjust multiplier as needed
    float satisfaction = maxSatisfaction - taxImpact;
    return std::clamp(satisfaction, 0.0f, maxSatisfaction);
}