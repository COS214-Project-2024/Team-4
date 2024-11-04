/**
 * @file Income.h
 * @brief Definition of the Income class.
 * @version 1.0
 * 
 * This file contains the definition of the Income class, which provides methods to calculate
 * monthly income, add bonuses, apply deductions, and calculate taxes.
 */

#ifndef INCOME_H
#define INCOME_H

#include "TaxType.h"
#include <string>

/**
 * @class Income
 * @brief Manages income-related operations.
 * 
 * The Income class provides methods to calculate monthly income, add bonuses, apply deductions,
 * and calculate taxes.
 */
class Income : public TaxType {

private:
    double incomeTax;       ///< Tax rate applied to the income
    char cType;             ///< Category type of the income
    double baseSalary;      ///< Base salary for the job
    double bonus;           ///< Monthly bonus (if any)
    double deductions;      ///< Monthly deductions (if any)

public:
    /**
     * @brief Constructor to initialize with base salary, tax rate, and category.
     * @param salary The base salary.
     * @param rate The tax rate.
     * @param category The category type.
     */
    Income(double salary, double rate, const char category) 
        : TaxType(rate, category), baseSalary(salary), bonus(0.0), deductions(0.0) {}

    /**
     * @brief Constructor to initialize with base salary.
     * @param salary The base salary.
     */
    Income(double salary) : Income(salary, 0.0, 'A') {}

    /**
     * @brief Calculates the monthly income considering base salary, bonuses, and deductions.
     * @return The calculated monthly income.
     */
    double calculateMonthlyIncome() const;

    /**
     * @brief Adds a bonus to the income for the current month.
     * @param amount The amount of the bonus to add.
     */
    void addBonus(double amount);

    /**
     * @brief Applies deductions for the current month.
     * @param amount The amount of deductions to apply.
     */
    void applyDeductions(double amount);

    /**
     * @brief Calculates and pays taxes based on the tax type.
     * @param taxType The type of tax to calculate.
     * @return The amount of taxes paid.
     */
    double payTaxes(TaxType& taxType);

    /**
     * @brief Sets the tax rate for the income.
     * @param rate The tax rate to set.
     */
    void setTax(double rate) override;

    /**
     * @brief Calculates the tax based on a given value.
     * @param val The value to calculate the tax on.
     * @return The calculated tax.
     */
    double calculateTax(double val) override;

    // Getters
    /**
     * @brief Gets the base salary.
     * @return The base salary.
     */
    double getBaseSalary() const { return baseSalary; }

    /**
     * @brief Gets the bonus.
     * @return The bonus.
     */
    double getBonus() const { return bonus; }

    /**
     * @brief Gets the deductions.
     * @return The deductions.
     */
    double getDeductions() const { return deductions; }
};

#endif // INCOME_H