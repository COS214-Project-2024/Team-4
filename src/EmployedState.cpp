#include "EmployedState.h"
#include "Citizen.h"

void EmployedState::handleState(Citizen& citizen) const {
    // Increase satisfaction due to employment
    citizen.updateSatisfaction(citizen.getSatisfactionLevel() + 10.0);
}

