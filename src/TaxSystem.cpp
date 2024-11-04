#include "TaxSystem.h"
#include "CollectTaxesCommand.h"
#include "SetTaxCommand.h"
#include "TaxType.h"
#include "Government.h"
#include "Building.h"
#include "Citizen.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>
#

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
        double collectedTax = building->payTaxes(it->second.get());

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
void TaxSystem::removeTaxRate(std::shared_ptr<TaxType> taxType) {
    auto it = std::find_if(taxRates.begin(), taxRates.end(),
                           [taxType](const std::pair<char, std::shared_ptr<TaxType>>& pair) {
                               return pair.second == taxType;
                           });
    if (it != taxRates.end()) {
        taxRates.erase(it);
    }
}

void TaxSystem::setTax(double rate, char taxType) {
    std::unique_ptr<GovCommand> setTaxCommand = std::make_unique<SetTaxCommand>(government, this, rate, taxType);
    setTaxCommand->execute();
}
// void TaxSystem::addTaxRate(TaxType* tax) {
//     char type = tax->getTaxType();
//     auto result = taxRates.insert(std::make_pair(type, tax));
//     if (!result.second) {
//         std::cout << "Tax rate for type " << type << " already exists." << std::endl;
//     }
// }

void TaxSystem::addSharedTaxRate(std::shared_ptr<TaxType> tax) {
    char type = tax->getTaxType();
    auto result = taxRates.insert(std::make_pair(type, tax));
    if (!result.second) {
        std::cout << "Tax rate for type " << type << " already exists." << std::endl;
    }
}


// void TaxSystem::collectTaxes(Building* building, char taxType) {
//     auto it = taxRates.find(taxType);
//     if (it != taxRates.end()) {
//         double collectedTax = building->payTaxes(it->second.get());

//         // Update government's budget with the collected tax
//         if (government) {
//             government->addTaxesToBudget(collectedTax);
//         } else {
//             std::cout << "No government assigned to receive taxes.\n";
//         }
//     } else {
//         std::cout << "Tax type not found for collection.\n";
//     }
// }

void TaxSystem::checkImpact(Building* building, std::shared_ptr<TaxType> newTaxType) {
    const std::string& type = building->getType();

    if (type == "Residential") {
        auto residentialBuilding = dynamic_cast<ResidentialBuilding*>(building);
        if (residentialBuilding) {
            double impact = residentialBuilding->getTotalImpact(newTaxType.get());
            std::cout << "Impact Report for Residential Building:\n";
            std::cout << "---------------------------------------\n";
            std::cout << "Building Name: " << residentialBuilding->getName() << "\n";
            std::cout << "New Tax Rate: " << newTaxType->getTaxRate() << "\n";
            std::cout << "Impact on Residents: " << impact << "%\n";
            std::cout << "---------------------------------------\n";
        }
    } else if (type == "Commercial" || type == "Industrial") {
        auto commercialBuilding = dynamic_cast<CommercialBuilding*>(building);
        if (commercialBuilding) {
            auto business = commercialBuilding->getBusiness();
            if (business) {
                double revenue = business->getRevenue();

                // Calculate current tax
                double currentTaxRate = business->getTaxRate();
                double currentTax = revenue * currentTaxRate;

                // Calculate new tax
                double newTaxRate = newTaxType->getTaxRate();
                double newTax = revenue * newTaxRate;

                // Calculate the percentage impact
                double impact = 0.0;
                if (currentTax != 0.0) {
                    impact = ((newTax - currentTax) / currentTax) * 100.0;
                }

                std::cout << "Impact Report for Commercial/Industrial Building:\n";
                std::cout << "-----------------------------------------------\n";
                std::cout << "Building Name: " << commercialBuilding->getName() << "\n";
                std::cout << "New Tax Rate: " << newTaxType->getTaxRate() << "\n";
                std::cout << "Impact on Business: " << impact << "%\n";
                std::cout << "-----------------------------------------------\n";
            } else {
                std::cout << "No business in the building to calculate impact.\n";
            }
        }
    } else {
        std::cout << "Building type not supported for impact check.\n";
    }
}