#ifndef SETTAXCOMMAND_H
#define SETTAXCOMMAND_H

#include "GovCommand.h"
#include "TaxType.h"
#include "Government.h"
#include "TaxSystem.h"
#include <iostream>

class SetTaxCommand : public GovCommand {
private:
    Government* government;
    TaxSystem* taxSys;
    double taxRate;
    char taxType;
    double previousTaxRate;
    TaxType* newTaxType;

public:
    SetTaxCommand(Government* gov, TaxSystem* taxSys, double rate, char taxType);
    void execute() override;
    void undo() override;
    double returnVal() override;

};
#endif
