#include "UnemployedState.h"
#include "Citizen.h"
#include <algorithm>

void UnemployedState::handleState(Citizen& citizen) const {
    // Decrease satisfaction due to unemployment
    double newSatisfaction = std::clamp(citizen.getSatisfactionLevel() - 10.0, 0.0, 100.0);
    citizen.setSatisfactionLevel(newSatisfaction);  // Use this if setSatisfactionLevel is added
    
}

