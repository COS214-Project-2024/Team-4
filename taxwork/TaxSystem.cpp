// TaxSystem.cpp

#include "TaxSystem.h"
#include "CollectTaxesCommand.h"
#include "SetTaxCommand.h"

void TaxSystem::addGovernment(std::shared_ptr<Government> gov) {
    government = gov;
}

void TaxSystem::addIncomeTaxBuilding(std::shared_ptr<Building> building) {
    if (building->getType() == "Residential") {
        incomeTaxbuildings.push_back(building);
    } else if (building->getType() == "Commercial") {
        incomeTaxbuildings.push_back(building);
    } else if (building->getType() == "Industrial") {
        incomeTaxbuildings.push_back(building);
    } else if (building->getType() == "Government") {
        std::cout << "Government building does not collect taxes" << std::endl;
    } else {
        std::cout << "Building type cannot be taxed" << std::endl;
    }
}

void TaxSystem::addPropertyTaxBuilding(std::shared_ptr<Building> building) {
    if (building->getType() == "Residential") {
        propertyTaxbuildings.push_back(building);
    } else if (building->getType() == "Commercial") {
        propertyTaxbuildings.push_back(building);
    } else if (building->getType() == "Industrial") {
        propertyTaxbuildings.push_back(building);
    } else if (building->getType() == "Government") {
        std::cout << "Government building does not collect taxes" << std::endl;
    } else {
        std::cout << "Building type cannot be taxed" << std::endl;
    }
}

void TaxSystem::addSalesTaxBuilding(std::shared_ptr<Building> building) {
    if (building->getType() == "Residential") {
        std::cout << "Residential building does not collect taxes for sales" << std::endl;
    } else if (building->getType() == "Commercial") {
        salesTaxbuildings.push_back(building);
    } else if (building->getType() == "Industrial") {
        salesTaxbuildings.push_back(building);
    } else if (building->getType() == "Government") {
        std::cout << "Government building does not collect taxes for sales" << std::endl;
    } else {
        std::cout << "Building type cannot be taxed" << std::endl;
    }
}

void TaxSystem::addVATTaxPayer(std::shared_ptr<Citizen> citizen) {
    vatTaxpayers.push_back(citizen);
}

void TaxSystem::removeIncomeTaxBuilding(std::shared_ptr<Building> building) {
    incomeTaxbuildings.erase(std::remove(incomeTaxbuildings.begin(), incomeTaxbuildings.end(), building), incomeTaxbuildings.end());
}

void TaxSystem::removePropertyTaxBuilding(std::shared_ptr<Building> building) {
    propertyTaxbuildings.erase(std::remove(propertyTaxbuildings.begin(), propertyTaxbuildings.end(), building), propertyTaxbuildings.end());
}

void TaxSystem::removeSalesTaxBuilding(std::shared_ptr<Building> building) {
    salesTaxbuildings.erase(std::remove(salesTaxbuildings.begin(), salesTaxbuildings.end(), building), salesTaxbuildings.end());
}

void TaxSystem::removeVATTaxPayer(std::shared_ptr<Citizen> citizen) {
    vatTaxpayers.erase(std::remove(vatTaxpayers.begin(), vatTaxpayers.end(), citizen), vatTaxpayers.end());
}

void TaxSystem::updateTaxRate(char cType, double rate) {
    auto it = taxRates.find(cType);
    if (it != taxRates.end()) {
        it->second->setTax(rate);
    }
}

void TaxSystem::collectTaxes(std::shared_ptr<Building> building, char taxType) {
    auto it = taxRates.find(taxType);
    if (it != taxRates.end()) {
        std::shared_ptr<GovCommand> command = std::make_shared<CollectTaxesCommand>(building, it->second);
        command->execute();
        command->returnVal();
    } else {
        std::cout << "Tax type not found" << std::endl;
    }
}

void TaxSystem::setTax(double rate, char taxType) {
    std::shared_ptr<GovCommand> setTaxCommand = std::make_shared<SetTaxCommand>(government, this, rate, taxType);
    setTaxCommand->execute();
}

void TaxSystem::checkImpact() {
    // TODO - implement TaxSystem::addTaxRate
    throw "Not yet implemented";
}

void TaxSystem::addTaxRate(std::shared_ptr<TaxType> tax) {
    taxRates.insert(std::make_pair(tax->getTaxRate(), tax));
}

void TaxSystem::removeTaxRate(std::shared_ptr<TaxType> taxType) {
    auto it = std::find_if(taxRates.begin(), taxRates.end(),
                           [taxType](const std::pair<char, std::shared_ptr<TaxType>>& pair) {
                               return pair.second == taxType;
                           });
    if (it != taxRates.end()) {
        taxRates.erase(it);
    }
}