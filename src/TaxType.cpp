/**
 * @file TaxType.cpp
 * @brief Implementation of the TaxType class.
 * 
 * This file contains the implementation of the TaxType class, which represents 
 * a specific type of tax with a rate and type identifier.
 * 
 * @version 1.0
 * @date 2023-10-05
 * 
 */

#include "TaxType.h"

/**
 * @brief Constructs a new TaxType object.
 * 
 * @param rate The tax rate.
 * @param type The character representing the tax type.
 */
TaxType::TaxType(double rate, char type) {
    this->taxRate = rate;
    this->cType = type;
}

/**
 * @brief Calculates the tax based on a given value.
 * 
 * @param val The value to calculate tax on.
 * @return The calculated tax.
 */
double TaxType::calculateTax(double val) {
    return val * taxRate;
}

/**
 * @brief Sets the tax rate.
 * 
 * @param rate The new tax rate.
 */
void TaxType::setTax(double rate) {
    this->taxRate = rate;
}

/**
 * @brief Gets the current tax rate.
 * 
 * @return The current tax rate.
 */
double TaxType::getTaxRate() {
    return taxRate;
}

/**
 * @brief Gets the tax type identifier.
 * 
 * @return The character representing the tax type.
 */
char TaxType::getTaxType() {
    return cType;
}