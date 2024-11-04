#include "UnsatisfiedState.h"
#include "Citizen.h"
#include <algorithm>

void UnsatisfiedState::handleState(Citizen& citizen) const {
    // Lower satisfaction
    double newSatisfaction = std::clamp(citizen.getSatisfactionLevel() - 50.0, 0.0, 100.0);
    citizen.setSatisfactionLevel(newSatisfaction);  // Use this if setSatisfactionLevel is added
    
}
