#ifndef COLLECTTAXESCOMMAND_H
#define COLLECTTAXESCOMMAND_H

#include "GovCommand.h"
#include "Government.h"
#include "Building.h"
class CollectTaxesCommand : public GovCommand {
private:
	Building* building;
	double taxesCollected;
	double taxRate;

public:
	CollectTaxesCommand(Building* building, double taxRate);
	void execute();
	void undo();
	double getTaxesCollected();
	double returnVal();
};

#endif
