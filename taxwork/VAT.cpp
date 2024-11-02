#include "VAT.h"

// Constructor to initialize VAT rate
VAT::VAT(double rate) : TaxType(rate, 'V'), vat(rate) {
    // Initialize vat using initializer list
}

void VAT::setTax(double rate) {
    vat = rate;
}

double VAT::calculateTax(double val) {
    // Calculate VAT as a percentage of the value
    return val * (vat / 100.0);
}