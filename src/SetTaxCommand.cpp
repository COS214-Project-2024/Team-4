#include "SetTaxCommand.h"

// Constructor for SetTaxCommand
// Initializes the command with the government object and the new tax rate
SetTaxCommand::SetTaxCommand(Government* gov, double rate) : government(gov), taxRate(rate) {}

// Executes the set tax command
// Stores the previous tax rate and sets the new tax rate
void SetTaxCommand::execute() {
    previousTaxRate = government->getTaxRate();
    government->setTax(taxRate);
}

// Undoes the set tax command
// Reverts the tax rate to the previous rate
void SetTaxCommand::undo() {
    government->setTax(previousTaxRate);
}