#include "Business.h"
#include <iostream>

using namespace std;

Business::Business(double revenue, double taxRate)
    : revenue(revenue), taxRate(taxRate), taxCooldownPeriod(std::chrono::seconds(10)) { // Default cooldown period of 10 seconds
}


Business::~Business() {
    // Destructor implementation (if needed)
}

void Business::updateTaxRate(double rate) {
    taxRate = rate;
    cout << "Business tax rate updated to " << taxRate << "%" << endl;
}

void Business::updatePolicy(Policy policy) {
    cout << "Business policy updated." << endl;
}

void Business::updateServices(CityService service) {
    cout << "Business services updated." << endl;
}

double Business::payTaxes(TaxType* taxType) {
    char taxTypeChar = taxType->getTaxType();
    auto now = std::chrono::steady_clock::now();

    // Check if the business is on cooldown for this tax type
    auto it = lastTaxPayments.find(taxTypeChar);
    if (it != lastTaxPayments.end()) {
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - it->second);
        if (elapsed < taxCooldownPeriod) {
            cout << "Business is on cooldown for tax type " << taxTypeChar << ". Taxes cannot be collected now.\n";
            return 0.0;
        }
    }

    double tax = taxType->calculateTax(revenue);
    if (tax > 0.0) {
        revenue -= tax;
        lastTaxPayments[taxTypeChar] = now; // Update last payment time for this tax type
        cout << "Business paid $" << tax << " in taxes for tax type " << taxTypeChar << ". Remaining revenue: " << revenue << endl;
        return tax;
    } else {
        cout << "Business has insufficient revenue to pay taxes.\n";
        return 0.0;
    }
}

void Business::setTaxCooldownPeriod(int seconds) {
    taxCooldownPeriod = std::chrono::seconds(seconds);
}