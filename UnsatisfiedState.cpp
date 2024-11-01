#include "UnsatisfiedState.h"
#include "Citizen.h"

void UnsatisfiedState::handleState(Citizen& citizen) const {
    // Lower satisfaction
    citizen.updateSatisfaction(citizen.getSatisfactionLevel() - 10.0);
}
