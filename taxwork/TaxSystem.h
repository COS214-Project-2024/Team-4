#ifndef TAXSYSTEM_H
#define TAXSYSTEM_H

#include "Citizen.h"
#include "Business.h"
#include "Building.h"
#include "GovCommand.h"
#include "TaxType.h"
#include "Income.h"
#include "Sales.h"
#include "CollectTaxesCommand.h"
#include "Property.h"
#include <vector>
#include <string>
#include <iostream>
#include "Sales.h"
#include <map>
class TaxSystem {
private:
    std::map<double, TaxType*> taxRates;
    // std::map<Citizen*, char> citizenTaxPayers;
    // std::map<Business*, char> businessTaxPayers;
    std::vector<Building*> incomeTaxbuildings;
    std::vector<Building*> propertyTaxbuildings;
    std::vector<Building*> salesTaxbuildings;
    std::vector<Citizen*> vatTaxpayers;
    
public:
    // void addCitizenTaxPayer(Citizen* taxPayer, char tType);
    //  void addBusinessTaxPayer(Business* bTaxPayer);
    void setTax(double rate, char taxType);
    // void removeCitizenTaxPayer(Citizen* taxPayer);
    // void removeBusinessTaxPayer(Business* bTaxPayer);
    void addIncomeTaxBuilding(Building* building);
    void addPropertyTaxBuilding(Building* building);
    void addSalesTaxBuilding(Building* building);
    void addVATTaxPayer(Citizen* citizen);
    void removeIncomeTaxBuilding(Building* building);
    void removePropertyTaxBuilding(Building* building);
    void removeSalesTaxBuilding(Building* building);
    void removeVATTaxPayer(Citizen* citizen);
    void updateTaxRate(char cType, double rate);
    void collectTaxes(Building* building,char taxType);
    void addTaxRate(TaxType* tax);
    void removeTaxRate(TaxType* tax);
    void checkImpact();
};

#endif
