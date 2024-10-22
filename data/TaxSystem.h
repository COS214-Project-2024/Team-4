#ifndef TAXSYSTEM_H
#define TAXSYSTEM_H

#include "Citizen.h"
#include "Business.h"
#include "Building.h"
#include "GovCommand.h"
class TaxSystem {


public:
	void addCitizenTaxPayer(Citizen* taxPayer, char tType);

	void addBusinessTaxPayer(Business* bTaxPayer, char tType);

	void setTax(double rate, char taxType);

	void removeCitizenTaxPayer(Citizen* taxPayer, char tType);

	void removeBusinessTaxPayer(Business* bTaxPayer, char tType);

	void getTaxPayers(int t, char taxType);

	void updateTaxRate(char cType);

	void collectTaxes(Building* building, GovCommand* command);

	TaxSystem();

	void setTax(double rate);

	void addTaxRate(GovCommand setTax);
};

#endif
