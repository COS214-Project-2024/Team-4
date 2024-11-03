#ifndef SETTAXCOMMAND_H
#define SETTAXCOMMAND_H

#include "GovCommand.h"
#include "Government.h"
#include "TaxSystem.h"

// SetTaxCommand class
// This class represents a command to set the tax rate in the government
class SetTaxCommand : public GovCommand {

private:
    Government* government;   // Pointer to the government object
    double taxRate;           // New tax rate to be set
    double previousTaxRate;   // Previous tax rate to revert if needed

public:
    // Constructor
    // Initializes the command with the government object and the new tax rate
    SetTaxCommand(Government* gov, double rate);
    SetTaxCommand(Government* gov, TaxSystem* taxSys, double rate, char category);

    // Executes the set tax command
    void execute() override;

    // Undoes the set tax command
    void undo() override;

    // Gets the name of the command
    std::string getName() const override;

    // Gets the description of the command
    std::string getDescription() const override;

    // Checks if the command can be executed
    bool canExecute() const override;
};

#endif