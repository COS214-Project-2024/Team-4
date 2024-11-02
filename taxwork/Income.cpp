#include "Income.h"

Income::Income(double rate) : TaxType(rate, 'I'), incomeTax(rate) {
    // Initialize incomeTax in the initializer list
}

double Income::calculateTax(double val) {
    if (val <= 30000) {
        return val * (incomeTax / 100.0);
    } else if (val <= 70000) {
        return 30000 * (incomeTax / 100.0) + 
               (val - 30000) * ((incomeTax + 2) / 100.0);
    } else {
        return 30000 * (incomeTax / 100.0) + 
               40000 * ((incomeTax + 2) / 100.0) + 
               (val - 70000) * ((incomeTax + 5) / 100.0);
    }
}

void Income::setTax(double rate) {
    this->incomeTax = rate;
}

