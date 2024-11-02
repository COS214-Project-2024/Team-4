#ifndef SETTAXCOMMAND_H
#define SETTAXCOMMAND_H

#include "GovCommand.h"
#include "TaxType.h"
#include "Government.h"


class SetTaxCommand : GovCommand {

private:
	void execute();
	void undo();
	TaxType* taxType;

public:
	void setTaxCommand(double rate);

	Government government();

	double prevTaxRate();
};

#endif
