#ifndef SETTAXCOMMAND_H
#define SETTAXCOMMAND_H

#include "GovCommand.h"
#include "Government.h"

class SetTaxCommand : public GovCommand {

private:
    Government* government;
    double taxRate;
    double previousTaxRate;

public:
    SetTaxCommand(Government* gov, double rate);

    void execute() override;
    void undo() override;
};

#endif
