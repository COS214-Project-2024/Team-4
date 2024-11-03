#include "TaxSatisfactionStrategy.h"
#include "Citizen.h"

float TaxSatisfactionStrategy::calculateSatisfaction(const Citizen& citizen) {
    // Higher tax rate lowers satisfaction
    float taxImpact = citizen.getTaxRate() * 50.0f; // Scales impact based on tax rate
    return std::max(citizen.getSatisfactionLevel() - taxImpact, 0.0f);
}

void TaxSatisfactionStrategy::updateForTaxChange(Citizen& citizen) {
    float taxImpact = citizen.getTaxRate() * 10.0f; // Small impact per tax change
    citizen.updateSatisfaction(std::max(citizen.getSatisfactionLevel() - taxImpact, 0.0f));
}



