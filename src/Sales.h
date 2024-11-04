/**
 * @file Sales.h
 * @brief Header file for the Sales class.
 * 
 * This file contains the definition of the Sales class, which represents a type of tax 
 * that includes a base sales tax, an environmental levy, and a service fee.
 * 
 * @version 1.0
 * @date 2024-11-04
 */

#ifndef SALES_H
#define SALES_H

#include "TaxType.h"

/**
 * @class Sales
 * @brief Represents a type of tax that includes a base sales tax, an environmental levy, and a service fee.
 * 
 * The Sales class inherits from the TaxType class and provides methods to set and calculate 
 * the total sales tax based on a sale amount.
 */
class Sales : public TaxType {
private:
    double salesTax;          ///< Base sales tax rate as a percentage.
    double environmentalLevy; ///< Additional environmental levy as a percentage.
    double serviceFee;        ///< Fixed service fee.

public:
    /**
     * @brief Constructs a new Sales object.
     * 
     * @param rate The base sales tax rate.
     * @param levy The environmental levy rate.
     * @param fee The fixed service fee.
     */
    Sales(double rate, double levy, double fee);

    /**
     * @brief Destroys the Sales object.
     */
    virtual ~Sales() override;

    /**
     * @brief Sets the base sales tax rate.
     * 
     * @param rate The new sales tax rate.
     */
    void setTax(double rate) override;

    /**
     * @brief Calculates the total sales tax based on the sale amount.
     * 
     * @param saleAmount The amount of the sale.
     * @return The total sales tax.
     */
    double calculateTax(double saleAmount) override;

    /**
     * @brief Sets the environmental levy rate.
     * 
     * @param levy The new environmental levy rate.
     */
    void setEnvironmentalLevy(double levy);

    /**
     * @brief Sets the fixed service fee.
     * 
     * @param fee The new service fee.
     */
    void setServiceFee(double fee);
};

#endif // SALES_H