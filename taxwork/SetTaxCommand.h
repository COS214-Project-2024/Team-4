#ifndef SETTAXCOMMAND_H
#define SETTAXCOMMAND_H

#include "GovCommand.h"
#include "TaxType.h"
#include "Government.h"


class SetTaxCommand : public GovCommand {

public:

    SetTaxCommand(Government* gov, double rate);

    void execute() override;

    void undo() override;

	double returnVal() override;


private:

    Government* government;

    double taxRate;

    double previousTaxRate;

};
#endif
