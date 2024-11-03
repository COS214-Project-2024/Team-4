#ifndef COLLECTTAXESCOMMAND_H
#define COLLECTTAXESCOMMAND_H

#include "GovCommand.h"
#include "Government.h"

// CollectTaxesCommand class
// This class represents a command to collect taxes from the government
class CollectTaxesCommand : public GovCommand {

private:
    Government* government;   // Pointer to the government object
    double collectedTaxes;    // Amount of taxes collected

public:
    // Constructor
    // Initializes the command with the government object
    CollectTaxesCommand(Government* gov);

    // Executes the tax collection command
    void execute() override;

    // Undoes the tax collection command
    void undo() override;
};

#endif