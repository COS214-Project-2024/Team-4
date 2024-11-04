// TaxSystem.h

#ifndef TAXSYSTEM_H
#define TAXSYSTEM_H

#include <vector>
#include <map>
#include <algorithm>
#include "Building.h"
#include "Citizen.h"
#include "TaxType.h"
#include "Government.h"

/**
 * @class TaxSystem
 * @brief Manages various types of taxes, including income, property, sales, and VAT.
 * 
 * This class allows adding and removing buildings and citizens for tax purposes, 
 * updating tax rates, and collecting taxes.
 * 
 * @version 1.0
 * @date 2023-10-05
 */
class TaxSystem {
public:
    /**
     * @brief Adds a government to the tax system.
     * 
     * @param gov Pointer to the government object.
     */
    void addGovernment(Government* gov);

    /**
     * @brief Adds a building to the income tax list.
     * 
     * @param building Pointer to the building object.
     */
    void addIncomeTaxBuilding(Building* building);

    /**
     * @brief Adds a building to the property tax list.
     * 
     * @param building Pointer to the building object.
     */
    void addPropertyTaxBuilding(Building* building);

    /**
     * @brief Adds a building to the sales tax list.
     * 
     * @param building Pointer to the building object.
     */
    void addSalesTaxBuilding(Building* building);

    /**
     * @brief Adds a citizen to the VAT tax list.
     * 
     * @param citizen Pointer to the citizen object.
     */
    void addVATTaxPayer(Citizen* citizen);

    /**
     * @brief Removes a building from the income tax list.
     * 
     * @param building Pointer to the building object.
     */
    void removeIncomeTaxBuilding(Building* building);

    /**
     * @brief Removes a building from the property tax list.
     * 
     * @param building Pointer to the building object.
     */
    void removePropertyTaxBuilding(Building* building);

    /**
     * @brief Removes a building from the sales tax list.
     * 
     * @param building Pointer to the building object.
     */
    void removeSalesTaxBuilding(Building* building);

    /**
     * @brief Removes a citizen from the VAT tax list.
     * 
     * @param citizen Pointer to the citizen object.
     */
    void removeVATTaxPayer(Citizen* citizen);

    /**
     * @brief Updates the tax rate for a specific tax type.
     * 
     * @param cType Character representing the tax type.
     * @param rate New tax rate.
     */
    void updateTaxRate(char cType, double rate);

    /**
     * @brief Collects taxes from a building based on the tax type.
     * 
     * @param building Pointer to the building object.
     * @param taxType Character representing the tax type.
     */
    void collectTaxes(Building* building, char taxType);

    /**
     * @brief Sets the tax rate for a specific tax type.
     * 
     * @param rate New tax rate.
     * @param taxType Character representing the tax type.
     */
    void setTax(double rate, char taxType);

    /**
     * @brief Checks the impact of the tax system.
     * 
     * This function is currently not implemented.
     */
    void checkImpact();

    /**
     * @brief Adds a new tax rate to the tax system.
     * 
     * @param tax Pointer to the TaxType object.
     */
    void addTaxRate(TaxType* tax);

    /**
     * @brief Removes a tax rate from the tax system.
     * 
     * @param taxType Pointer to the TaxType object.
     */
    void removeTaxRate(TaxType* taxType);
    
private:
    Government* government;
    std::vector<Building*> incomeTaxbuildings;
    std::vector<Building*> propertyTaxbuildings;
    std::vector<Building*> salesTaxbuildings;
    std::vector<Citizen*> vatTaxpayers;
    std::map<char, TaxType*> taxRates;
    float totalTaxCollected = 0.0;
};

#endif // TAXSYSTEM_H