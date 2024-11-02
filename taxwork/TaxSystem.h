// TaxSystem.h

#ifndef TAXSYSTEM_H
#define TAXSYSTEM_H

#include <vector>
#include <map>
#include <memory>
#include <algorithm>
#include "Building.h"
#include "Citizen.h"
#include "TaxType.h"
#include "Government.h"

class TaxSystem {
public:
    void addGovernment(std::shared_ptr<Government> gov);
    void addIncomeTaxBuilding(std::shared_ptr<Building> building);
    void addPropertyTaxBuilding(std::shared_ptr<Building> building);
    void addSalesTaxBuilding(std::shared_ptr<Building> building);
    void addVATTaxPayer(std::shared_ptr<Citizen> citizen);
    void removeIncomeTaxBuilding(std::shared_ptr<Building> building);
    void removePropertyTaxBuilding(std::shared_ptr<Building> building);
    void removeSalesTaxBuilding(std::shared_ptr<Building> building);
    void removeVATTaxPayer(std::shared_ptr<Citizen> citizen);
    void updateTaxRate(char cType, double rate);
    void collectTaxes(std::shared_ptr<Building> building, char taxType);
    void setTax(double rate, char taxType);
    void checkImpact();
    void addTaxRate(std::shared_ptr<TaxType> tax);
    void removeTaxRate(std::shared_ptr<TaxType> taxType);

private:
    std::shared_ptr<Government> government;
    std::vector<std::shared_ptr<Building>> incomeTaxbuildings;
    std::vector<std::shared_ptr<Building>> propertyTaxbuildings;
    std::vector<std::shared_ptr<Building>> salesTaxbuildings;
    std::vector<std::shared_ptr<Citizen>> vatTaxpayers;
    std::map<char, std::shared_ptr<TaxType>> taxRates;
};

#endif // TAXSYSTEM_H
