// TaxSatisfactionStrategy.cpp

#include "TaxSatisfactionStrategy.h"
#include "Citizen.h"

float TaxSatisfactionStrategy::calculateSatisfaction(const Citizen& citizen) const {
    // Example: Lower tax rates yield higher satisfaction
    float taxRate = citizen.getTaxRate();
    return 100.0f - (taxRate * 100.0f);  // Higher satisfaction for lower tax rates
}
