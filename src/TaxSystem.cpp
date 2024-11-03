#include "TaxSystem.h"
#include "CollectTaxesCommand.h"
#include "SetTaxCommand.h"
#include <iostream>
#include <algorithm>

void TaxSystem::addGovernment(Government* gov) {
    government = gov;
}

void TaxSystem::addIncomeTaxBuilding(Building* building) {
    const std::string& type = building->getType();
    if (type == "Residential" || type == "Commercial" || type == "Industrial") {
        incomeTaxbuildings.push_back(building);
    } else {
        std::cout << "Building type cannot be taxed for income" << std::endl;
    }
}

void TaxSystem::addPropertyTaxBuilding(Building* building) {
    const std::string& type = building->getType();
    if (type == "Residential" || type == "Commercial" || type == "Industrial") {
        propertyTaxbuildings.push_back(building);
    } else {
        std::cout << "Building type cannot be taxed for property" << std::endl;
    }
}

void TaxSystem::addSalesTaxBuilding(Building* building) {
    const std::string& type = building->getType();
    if (type == "Commercial" || type == "Industrial") {
        salesTaxbuildings.push_back(building);
    } else {
        std::cout << "Building type cannot be taxed for sales" << std::endl;
    }
}


void TaxSystem::addVATTaxPayer(Citizen* citizen) {
    vatTaxpayers.push_back(citizen);
}

void TaxSystem::removeIncomeTaxBuilding(Building* building) {
    incomeTaxbuildings.erase(std::remove(incomeTaxbuildings.begin(), incomeTaxbuildings.end(), building), incomeTaxbuildings.end());
}

void TaxSystem::removePropertyTaxBuilding(Building* building) {
    propertyTaxbuildings.erase(std::remove(propertyTaxbuildings.begin(), propertyTaxbuildings.end(), building), propertyTaxbuildings.end());
}

void TaxSystem::removeSalesTaxBuilding(Building* building) {
    salesTaxbuildings.erase(std::remove(salesTaxbuildings.begin(), salesTaxbuildings.end(), building), salesTaxbuildings.end());
}

void TaxSystem::removeVATTaxPayer(Citizen* citizen) {
    vatTaxpayers.erase(std::remove(vatTaxpayers.begin(), vatTaxpayers.end(), citizen), vatTaxpayers.end());
}

void TaxSystem::updateTaxRate(char cType, double rate) {
    auto it = taxRates.find(cType);
    if (it != taxRates.end()) {
        it->second->setTax(rate);
    } else {
        std::cout << "Tax type not found." << std::endl;
    }
}

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

void TaxSystem::setTax(double rate, char taxType) {
    std::unique_ptr<GovCommand> setTaxCommand = std::make_unique<SetTaxCommand>(government, this, rate, taxType);
    setTaxCommand->execute();
}

void TaxSystem::checkImpact() {
    // Implement checkImpact logic here if necessary.
}

void TaxSystem::addTaxRate(TaxType* tax) {
    char type = tax->getTaxType();
    auto result = taxRates.insert(std::make_pair(type, tax));
    if (!result.second) {
        std::cout << "Tax rate for type " << type << " already exists." << std::endl;
    }
}

void TaxSystem::removeTaxRate(TaxType* taxType) {
    auto it = std::find_if(taxRates.begin(), taxRates.end(),
                           [taxType](const std::pair<char, TaxType*>& pair) {
                               return pair.second == taxType;
                           });
    if (it != taxRates.end()) {
        taxRates.erase(it);
    }
}
