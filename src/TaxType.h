#ifndef TAXTYPE_H
#define TAXTYPE_H

/**
 * @class TaxType
 * @brief Represents a specific type of tax with a rate and type identifier.
 * 
 * This class provides methods to calculate tax based on a given value, set and get the tax rate, 
 * and get the tax type identifier.
 * 
 * @version 1.0
 * @date 2024-11-04
 */
class TaxType {

private:
    double taxRate; ///< The tax rate.
    char cType; ///< The character representing the tax type.

public:
    /**
     * @brief Constructs a new TaxType object.
     * 
     * @param rate The tax rate.
     * @param type The character representing the tax type.
     */
    TaxType(double rate, char type);

    /**
     * @brief Virtual Destructor.
     */
    virtual ~TaxType() {} // Virtual Destructor

    /**
     * @brief Calculates the tax based on a given value.
     * 
     * @param val The value to calculate tax on.
     * @return The calculated tax.
     */
    virtual double calculateTax(double val);

    /**
     * @brief Sets the tax rate.
     * 
     * @param rate The new tax rate.
     */
    virtual void setTax(double rate);

    /**
     * @brief Gets the current tax rate.
     * 
     * @return The current tax rate.
     */
    virtual double getTaxRate();

    /**
     * @brief Gets the tax type identifier.
     * 
     * @return The character representing the tax type.
     */
    char getTaxType();
};

#endif // TAXTYPE_H