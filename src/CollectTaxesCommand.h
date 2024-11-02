#ifndef COLLECTTAXESCOMMAND_H
#define COLLECTTAXESCOMMAND_H

#include "GovCommand.h"
#include "Government.h"

class CollectTaxesCommand : public GovCommand {

private:
    Government* government;
    double collectedTaxes;

public:
    CollectTaxesCommand(Government* gov);

    void execute() override;
    void undo() override;
};

#endif