#include "LeavingCityState.h"
#include "Citizen.h"

void LeavingCityState::handleState(Citizen& citizen) const {
    // Drastically reduce satisfaction as citizen prepares to leave
    citizen.updateSatisfaction(citizen.getSatisfactionLevel() - 100.0);
}
