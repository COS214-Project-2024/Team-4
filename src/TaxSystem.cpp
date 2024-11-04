/**
 * @file TaxSystem.cpp
 * @brief Implementation of the TaxSystem class.
 * 
 * This file contains the implementation of the TaxSystem class, which manages 
 * various types of taxes, including income, property, sales, and VAT. It allows 
 * adding and removing buildings and citizens for tax purposes, updating tax rates, 
 * and collecting taxes.
 * 
 * @version 1.0
 * @date 2023-10-05
 * 
 */

#include "TaxSystem.h"
#include "CollectTaxesCommand.h"
#include "SetTaxCommand.h"
#include <iostream>
#include <algorithm>

/**
 * @brief Adds a government to the tax system.
 * 
 * @param gov Pointer to the government object.
 */
void TaxSystem::addGovernment(Government* gov) {
    government = gov;
}

/**
 * @brief Adds a building to the income tax list.
 * 
 * @param building Pointer to the building object.
 */
void TaxSystem::addIncomeTaxBuilding(Building* building) {
    const std::string& type = building->getType();
    if (type == "Residential" || type == "Commercial" || type == "Industrial") {
        incomeTaxbuildings.push_back(building);
    } else {
        std::cout << "Building type cannot be taxed for income" << std::endl;
    }
}

/**
 * @brief Adds a building to the property tax list.
 * 
 * @param building Pointer to the building object.
 */
void TaxSystem::addPropertyTaxBuilding(Building* building) {
    const std::string& type = building->getType();
    if (type == "Residential" || type == "Commercial" || type == "Industrial") {
        propertyTaxbuildings.push_back(building);
    } else {
        std::cout << "Building type cannot be taxed for property" << std::endl;
    }
}

/**
 * @brief Adds a building to the sales tax list.
 * 
 * @param building Pointer to the building object.
 */
void TaxSystem::addSalesTaxBuilding(Building* building) {
    const std::string& type = building->getType();
    if (type == "Commercial" || type == "Industrial") {
        salesTaxbuildings.push_back(building);
    } else {
        std::cout << "Building type cannot be taxed for sales" << std::endl;
    }
}

/**
 * @brief Adds a citizen to the VAT tax list.
 * 
 * @param citizen Pointer to the citizen object.
 */
void TaxSystem::addVATTaxPayer(Citizen* citizen) {
    vatTaxpayers.push_back(citizen);
}

/**
 * @brief Removes a building from the income tax list.
 * 
 * @param building Pointer to the building object.
 */
void TaxSystem::removeIncomeTaxBuilding(Building* building) {
    incomeTaxbuildings.erase(std::remove(incomeTaxbuildings.begin(), incomeTaxbuildings.end(), building), incomeTaxbuildings.end());
}

/**
 * @brief Removes a building from the property tax list.
 * 
 * @param building Pointer to the building object.
 */
void TaxSystem::removePropertyTaxBuilding(Building* building) {
    propertyTaxbuildings.erase(std::remove(propertyTaxbuildings.begin(), propertyTaxbuildings.end(), building), propertyTaxbuildings.end());
}

/**
 * @brief Removes a building from the sales tax list.
 * 
 * @param building Pointer to the building object.
 */
void TaxSystem::removeSalesTaxBuilding(Building* building) {
    salesTaxbuildings.erase(std::remove(salesTaxbuildings.begin(), salesTaxbuildings.end(), building), salesTaxbuildings.end());
}

/**
 * @brief Removes a citizen from the VAT tax list.
 * 
 * @param citizen Pointer to the citizen object.
 */
void TaxSystem::removeVATTaxPayer(Citizen* citizen) {
    vatTaxpayers.erase(std::remove(vatTaxpayers.begin(), vatTaxpayers.end(), citizen), vatTaxpayers.end());
}

/**
 * @brief Updates the tax rate for a specific tax type.
 * 
 * @param cType Character representing the tax type.
 * @param rate New tax rate.
 */
void TaxSystem::updateTaxRate(char cType, double rate) {
    auto it = taxRates.find(cType);
    if (it != taxRates.end()) {
        it->second->setTax(rate);
    } else {
        std::cout << "Tax type not found." << std::endl;
    }
}

/**
 * @brief Collects taxes from a building based on the tax type.
 * 
 * @param building Pointer to the building object.
 * @param taxType Character representing the tax type.
 */
void TaxSystem::collectTaxes(Building* building, char taxType) {
    auto it = taxRates.find(taxType);
    if (it != taxRates.end()) {
        double collectedTax = building->payTaxes(it->second);

        // Update government's budget with the collected tax
        if (government) {
            government->addTaxesToBudget(collectedTax);
        } else {
            std::cout << "No government assigned to receive taxes.\n";
        }
    } else {
        std::cout << "Tax type not found for collection.\n";
    }
}

/**
 * @brief Sets the tax rate for a specific tax type.
 * 
 * @param rate New tax rate.
 * @param taxType Character representing the tax type.
 */
void TaxSystem::setTax(double rate, char taxType) {
    std::unique_ptr<GovCommand> setTaxCommand = std::make_unique<SetTaxCommand>(government, this, rate, taxType);
    setTaxCommand->execute();
}

/**
 * @brief Checks the impact of the tax system.
 * 
 * This function is currently not implemented.
 */
void TaxSystem::checkImpact() {
    // Implement checkImpact logic here if necessary.
}

/**
 * @brief Adds a new tax rate to the tax system.
 * 
 * @param tax Pointer to the TaxType object.
 */
void TaxSystem::addTaxRate(TaxType* tax) {
    char type = tax->getTaxType();
    auto result = taxRates.insert(std::make_pair(type, tax));
    if (!result.second) {
        std::cout << "Tax rate for type " << type << " already exists." << std::endl;
    }
}

/**
 * @brief Removes a tax rate from the tax system.
 * 
 * @param taxType Pointer to the TaxType object.
 */
void TaxSystem::removeTaxRate(TaxType* taxType) {
    auto it = std::find_if(taxRates.begin(), taxRates.end(),
                           [taxType](const std::pair<char, TaxType*>& pair) {
                               return pair.second == taxType;
                           });
    if (it != taxRates.end()) {
        taxRates.erase(it);
    }
}