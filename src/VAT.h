/**
 * @file VAT.h
 * @brief Declaration of the VAT class.
 * 
 * This file contains the declaration of the VAT class, which handles the calculation and setting of Value Added Tax (VAT).
 * 
 * @version 1.0
 * @date 2023-10-05
 * 
 * @note This file is part of a larger project that simulates the behavior of citizens and buildings in a city.
 */

#ifndef VAT_H
#define VAT_H

#include "TaxType.h"

/**
 * @class VAT
 * @brief A class that represents Value Added Tax (VAT).
 * 
 * The VAT class is responsible for handling the calculation and setting of VAT.
 */
class VAT : public TaxType {
private:
    double vat;  ///< The VAT rate
    char cType;  ///< The type of tax

public:
    /**
     * @brief Sets the VAT rate.
     * 
     * This function sets the VAT rate to the specified value.
     * 
     * @param rate The VAT rate to be set.
     */
    void setTax(double rate);

    /**
     * @brief Calculates the VAT.
     * 
     * This function calculates the VAT based on the current rate and applicable amount.
     */
    void calculateTax();
};

#endif // VAT_H