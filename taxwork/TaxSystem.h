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
    std::map<Citizen*, char> citizenTaxPayers;
    std::map<Business*, char> businessTaxPayers;
    
public:
    void addCitizenTaxPayer(Citizen* taxPayer, char tType);
    void addBusinessTaxPayer(Business* bTaxPayer, char tType);
    void setTax(double rate, char taxType);
    void removeCitizenTaxPayer(Citizen* taxPayer);
    void removeBusinessTaxPayer(Business* bTaxPayer);
    void updateTaxRate(char cType, double rate);
    void collectTaxes(Building* building,char taxType);
    void addTaxRate(GovCommand setTax);
    void removeTaxRate(TaxType* tax);
    void checkImpact();
};

#endif
