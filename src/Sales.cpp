/**
 * @file Sales.cpp
 * @brief Implementation file for the Sales class.
 * 
 * This file contains the implementation of the Sales class, which represents a type of tax 
 * that includes a base sales tax, an environmental levy, and a service fee.
 * 
 * @version 1.0
 * @date 2023-10-05
 */

#include "Sales.h"

/**
 * @brief Constructs a new Sales object.
 * 
 * @param rate The base sales tax rate.
 * @param levy The environmental levy rate.
 * @param fee The fixed service fee.
 */
Sales::Sales(double rate, double levy, double fee)
    : TaxType(rate,'S'), salesTax(rate), environmentalLevy(levy), serviceFee(fee) {
}

/**
 * @brief Destroys the Sales object.
 */
Sales::~Sales() {
    // Cleanup resources if any
}

/**
 * @brief Sets the base sales tax rate.
 * 
 * @param rate The new sales tax rate.
 */
void Sales::setTax(double rate) {
    salesTax = rate;
}

/**
 * @brief Sets the environmental levy rate.
 * 
 * @param levy The new environmental levy rate.
 */
void Sales::setEnvironmentalLevy(double levy) {
    environmentalLevy = levy;
}

/**
 * @brief Sets the fixed service fee.
 * 
 * @param fee The new service fee.
 */
void Sales::setServiceFee(double fee) {
    serviceFee = fee;
}

/**
 * @brief Calculates the total sales tax for a given sale amount.
 * 
 * @param saleAmount The amount of the sale.
 * @return The total sales tax.
 */
double Sales::calculateTax(double saleAmount) {
    // Base sales tax as a percentage of the sale amount
    double baseTax = saleAmount * (salesTax / 100.0);

    // Environmental levy as a percentage of the sale amount
    double levyAmount = saleAmount * (environmentalLevy / 100.0);

    // Total tax includes base tax, environmental levy, and fixed service fee
    return baseTax + levyAmount + serviceFee;
}