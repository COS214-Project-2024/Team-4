#include "SatisfiedState.h"
#include "Citizen.h"

void SatisfiedState::handleState(Citizen& citizen) const {
    // Maintain or slightly boost satisfaction
    citizen.updateSatisfaction(citizen.getSatisfactionLevel() + 2.0);
}

