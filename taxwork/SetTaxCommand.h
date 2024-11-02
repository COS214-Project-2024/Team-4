#ifndef SETTAXCOMMAND_H
#define SETTAXCOMMAND_H

#include "GovCommand.h"
#include "TaxType.h"
#include "Government.h"
#include "TaxSystem.h"
#include <iostream>

class SetTaxCommand : public GovCommand {

public:

    SetTaxCommand(Government* gov, TaxSystem* taxSys, double rate, char taxType);

    void execute();

    void undo();

    double returnVal();

private:

    Government* government;

    TaxSystem* taxSys;

    double taxRate;

    double previousTaxRate;

    char taxType;
    TaxType* newTaxType;

};
#endif
