#ifndef COLLECTTAXESCOMMAND_H
#define COLLECTTAXESCOMMAND_H

#include "GovCommand.h"
#include "Government.h"
#include "Building.h"
#include "TaxType.h"
class CollectTaxesCommand : public GovCommand {
private:
	std::shared_ptr<Building> building;
	double taxesCollected;
	double taxRate;
	std::shared_ptr<TaxType> taxType;

public:
	CollectTaxesCommand(std::shared_ptr<Building> building, std::shared_ptr<TaxType> taxType);
	void execute();
	void undo();
	double getTaxesCollected();
	double returnVal();
};

#endif
