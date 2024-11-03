#include "JobSatisfactionStrategy.h"
#include "Citizen.h"

float JobSatisfactionStrategy::calculateSatisfaction(const Citizen& citizen) {
    if (citizen.isEmployed()) {
        return std::min(citizen.getSatisfactionLevel() + 10.0f, 100.0f); // Increase if employed
    } else {
        return std::max(citizen.getSatisfactionLevel() - 30.0f, 0.0f); // Decrease if unemployed
    }
}

void JobSatisfactionStrategy::updateForJobChange(Citizen& citizen) {
    if (citizen.isEmployed()) {
        citizen.updateSatisfaction(std::min(citizen.getSatisfactionLevel() + 5.0f, 100.0f)); // Small increase on job change
    } else {
        citizen.updateSatisfaction(std::max(citizen.getSatisfactionLevel() - 30.0f, 0.0f)); // Decrease on job loss
    }
}


