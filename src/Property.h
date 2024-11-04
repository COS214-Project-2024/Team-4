/**
 * @file Property.h
 * @brief Definition of the Property class.
 * @version 1.0
 * 
 * This file contains the definition of the Property class, which represents a property
 * with specific attributes and behaviors related to property tax calculation.
 */

#ifndef PROPERTY_H
#define PROPERTY_H

#include "TaxType.h"

/**
 * @class Property
 * @brief Represents a property with specific attributes and behaviors related to property tax calculation.
 * 
 * The Property class inherits from the TaxType class and provides methods to set tax rates,
 * calculate property tax, and set additional fees.
 */
class Property : public TaxType {
private:
    double propertyTax;   ///< Base property tax rate as a percentage
    double municipalLevy; ///< Additional municipal levy as a percentage
    double additionalFees; ///< Fixed additional fees

public:
    /**
     * @brief Constructor to initialize base property tax rate, municipal levy, and additional fees.
     * @param rate The base property tax rate.
     * @param levy The municipal levy rate.
     * @param fees Additional fixed fees.
     */
    Property(double rate, double levy, double fees);

    /**
     * @brief Sets the base property tax rate.
     * @param rate The base property tax rate.
     */
    void setTax(double rate) override;

    /**
     * @brief Calculates the total property tax for a given property value.
     * @param propertyValue The value of the property.
     * @return The total property tax.
     */
    double calculateTax(double propertyValue) override;

    /**
     * @brief Sets the municipal levy rate.
     * @param levy The municipal levy rate.
     */
    void setMunicipalLevy(double levy);

    /**
     * @brief Sets additional fixed fees.
     * @param fees The additional fixed fees.
     */
    void setAdditionalFees(double fees);
};

#endif // PROPERTY_H