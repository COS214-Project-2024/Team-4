// IncomeTax.cpp

#include "Income.h"

// Constructor
Income::Income(double rate) : TaxType(rate,'I'), rate(rate) {}

// Destructor
Income::~Income() {
    // Cleanup resources if any
}

// Calculate Tax
double Income::calculateTax(double income) {
    return income * rate;
}

