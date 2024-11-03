#include "Property.h"

// Constructor to initialize base property tax rate, municipal levy, and additional fees
Property::Property(double rate, double levy, double fees)
    : TaxType(rate,'P'), propertyTax(rate), municipalLevy(levy), additionalFees(fees) {
}

// Set the base property tax rate
void Property::setTax(double rate) {
    propertyTax = rate;
}

// Set the municipal levy rate
void Property::setMunicipalLevy(double levy) {
    municipalLevy = levy;
}

// Set additional fixed fees
void Property::setAdditionalFees(double fees) {
    additionalFees = fees;
}

// Calculate the total property tax for a given property value
double Property::calculateTax(double propertyValue) {
    // Base property tax as a percentage of the property value
    double baseTax = propertyValue * (propertyTax / 100.0);

    // Municipal levy as a percentage of the property value
    double levyAmount = propertyValue * (municipalLevy / 100.0);

    // Total tax is the sum of the base tax, levy, and additional fees
    return baseTax + levyAmount + additionalFees;
}