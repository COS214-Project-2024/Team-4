#include "EmployedState.h"
#include "Citizen.h"

// Function to clamp a value between a minimum and maximum
double clamp(double value, double min, double max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

void EmployedState::handleState(Citizen& citizen) const {
    double newSatisfaction = clamp(citizen.getSatisfactionLevel() + 10.0, 0.0, 100.0);
    citizen.setSatisfactionLevel(newSatisfaction);  // Use this if setSatisfactionLevel is added
    citizen.updateSatisfaction(); // Calls the no-parameter update
}


