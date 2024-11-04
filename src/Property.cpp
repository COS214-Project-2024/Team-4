/**
 * @file Property.cpp
 * @brief Implementation of the Property class.
 * @version 1.0
 * 
 * This file contains the implementation of the Property class, which represents a property
 * with specific attributes and behaviors related to property tax calculation.
 */

#include "Property.h"

/**
 * @brief Constructor to initialize base property tax rate, municipal levy, and additional fees.
 * @param rate The base property tax rate.
 * @param levy The municipal levy rate.
 * @param fees Additional fixed fees.
 */
Property::Property(double rate, double levy, double fees)
    : TaxType(rate,'P'), propertyTax(rate), municipalLevy(levy), additionalFees(fees) {
}

/**
 * @brief Sets the base property tax rate.
 * @param rate The base property tax rate.
 */
void Property::setTax(double rate) {
    propertyTax = rate;
}

/**
 * @brief Sets the municipal levy rate.
 * @param levy The municipal levy rate.
 */
void Property::setMunicipalLevy(double levy) {
    municipalLevy = levy;
}

/**
 * @brief Sets additional fixed fees.
 * @param fees The additional fixed fees.
 */
void Property::setAdditionalFees(double fees) {
    additionalFees = fees;
}

/**
 * @brief Calculates the total property tax for a given property value.
 * @param propertyValue The value of the property.
 * @return The total property tax.
 */
double Property::calculateTax(double propertyValue) {
    // Base property tax as a percentage of the property value
    double baseTax = propertyValue * (propertyTax / 100.0);

    // Municipal levy as a percentage of the property value
    double levyAmount = propertyValue * (municipalLevy / 100.0);

    // Total tax is the sum of the base tax, levy, and additional fees
    return baseTax + levyAmount + additionalFees;
}