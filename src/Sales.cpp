#include "Sales.h"

// Constructor to initialize base sales tax, environmental levy, and service fee
Sales::Sales(double rate, double levy, double fee)
    : TaxType(rate,'S'), salesTax(rate), environmentalLevy(levy), serviceFee(fee) {
}
Sales::~Sales() {
    // Cleanup resources if any
}
// Set the base sales tax rate
void Sales::setTax(double rate) {
    salesTax = rate;
}

// Set the environmental levy rate
void Sales::setEnvironmentalLevy(double levy) {
    environmentalLevy = levy;
}

// Set the fixed service fee
void Sales::setServiceFee(double fee) {
    serviceFee = fee;
}

// Calculate the total sales tax for a given sale amount
double Sales::calculateTax(double saleAmount) {
    // Base sales tax as a percentage of the sale amount
    double baseTax = saleAmount * (salesTax / 100.0);

    // Environmental levy as a percentage of the sale amount
    double levyAmount = saleAmount * (environmentalLevy / 100.0);

    // Total tax includes base tax, environmental levy, and fixed service fee
    return baseTax + levyAmount + serviceFee;
} 

