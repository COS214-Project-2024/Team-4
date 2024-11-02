#ifndef COLLECTTAXESCOMMAND_H
#define COLLECTTAXESCOMMAND_H

#include "GovCommand.h"
#include "Government.h"

class CollectTaxesCommand : public GovCommand {

public:
	Government* government;

	void execute();

	void undo();
};

#endif
