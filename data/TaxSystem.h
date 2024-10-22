#ifndef TAXSYSTEM_H
#define TAXSYSTEM_H

#include "Citizen.h"
#include "Business.h"
#include "Building.h"
#include "GovCommand.h"
class TaxSystem {
private:
    std::map<std::string, TaxType*> taxRates;
    std::map<Citizen*, char> citizenTaxPayers;
    std::map<Business*, char> businessTaxPayers;
    
public:
    TaxSystem();
    void addCitizenTaxPayer(Citizen* taxPayer, char tType);
    void addBusinessTaxPayer(Business* bTaxPayer, char tType);
    void setTax(double rate, char taxType);
    void removeCitizenTaxPayer(Citizen* taxPayer, char tType);
    void removeBusinessTaxPayer(Business* bTaxPayer, char tType);
    void updateTaxRate(char cType);
    void collectTaxes(Building* building, GovCommand* command);
    void checkImpact();
};

#endif
