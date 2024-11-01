#include "UnemployedState.h"
#include "Citizen.h"

void UnemployedState::handleState(Citizen& citizen) const {
    // Decrease satisfaction due to unemployment
    citizen.updateSatisfaction(citizen.getSatisfactionLevel() - 5.0);
}

