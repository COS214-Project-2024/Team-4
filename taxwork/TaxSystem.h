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

class TaxSystem {
public:
    void addGovernment(Government* gov);
    void addIncomeTaxBuilding(Building* building);
    void addPropertyTaxBuilding(Building* building);
    void addSalesTaxBuilding(Building* building);
    void addVATTaxPayer(Citizen* citizen);
    void removeIncomeTaxBuilding(Building* building);
    void removePropertyTaxBuilding(Building* building);
    void removeSalesTaxBuilding(Building* building);
    void removeVATTaxPayer(Citizen* citizen);
    void updateTaxRate(char cType, double rate);
    void collectTaxes(Building* building, char taxType);
    void setTax(double rate, char taxType);
    void checkImpact();
    void addTaxRate(TaxType* tax);
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
