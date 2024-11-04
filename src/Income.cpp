/**
 * @file Income.cpp
 * @brief Implementation of the Income class.
 * @version 1.0
 * 
 * This file contains the implementation of the Income class, which provides methods to calculate
 * monthly income, add bonuses, apply deductions, and calculate taxes.
 */

#include "Income.h"

/**
 * @brief Calculates the monthly income considering base salary, bonuses, and deductions.
 * @return The calculated monthly income.
 */
double Income::calculateMonthlyIncome() const {
    return baseSalary + bonus - deductions;
}

/**
 * @brief Adds a bonus to the income for the current month.
 * @param amount The amount of the bonus to add.
 */
void Income::addBonus(double amount) {
    bonus += amount;
}

/**
 * @brief Applies deductions for the current month.
 * @param amount The amount of deductions to apply.
 */
void Income::applyDeductions(double amount) {
    deductions += amount;
    deductions += incomeTax;
}

/**
 * @brief Sets the tax rate for the income.
 * @param taxRate The tax rate to set.
 */
void Income::setTax(double taxRate) {
    incomeTax = taxRate;
}

/**
 * @brief Calculates and pays taxes based on the tax type.
 * @param taxType The type of tax to calculate.
 * @return The amount of taxes paid.
 */
double Income::payTaxes(TaxType& taxType) {
    double taxRate = taxType.getTaxRate(); // Example usage of a method in TaxType
    return baseSalary * taxRate;
}

/**
 * @brief Calculates the tax based on a given value.
 * @param val The value to calculate the tax on.
 * @return The calculated tax.
 */
double Income::calculateTax(double val) {
    return val * incomeTax;
}