#include "HousingSatisfactionStrategy.h"
#include "Citizen.h"

float HousingSatisfactionStrategy::calculateSatisfaction(const Citizen& citizen) {
    return std::min(citizen.getSatisfactionLevel() + 7.0f, 100.0f); // Adjust for housing quality
}

void HousingSatisfactionStrategy::updateForHousingChange(Citizen& citizen) {
    citizen.updateSatisfaction(std::min(citizen.getSatisfactionLevel() + 3.0f, 100.0f)); // Small increase on housing upgrade
}


