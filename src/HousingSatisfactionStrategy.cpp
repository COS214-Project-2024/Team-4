// HousingSatisfactionStrategy.cpp

#include "HousingSatisfactionStrategy.h"
#include "Citizen.h"

float HousingSatisfactionStrategy::calculateSatisfaction(const Citizen& citizen) const {
    // Example logic: Higher satisfaction for higher housing comfort levels
    float comfortLevel = citizen.getHousingComfortLevel();
    return comfortLevel * 10.0f;  // Arbitrary calculation for demonstration
}
