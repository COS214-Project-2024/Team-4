#ifndef COLLECTTAXESCOMMAND_H
#define COLLECTTAXESCOMMAND_H

#include "GovCommand.h"
#include "Government.h"
#include "Building.h"
#include "TaxType.h"
class CollectTaxesCommand : public GovCommand {
private:
	Building* building;
	double taxesCollected;
	double taxRate;
	TaxType* taxType;

public:
	CollectTaxesCommand(Building* building, TaxType* taxType);
	void execute();
	void undo();
	double getTaxesCollected();
	double returnVal();
};

#endif
