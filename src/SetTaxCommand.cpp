#include "SetTaxCommand.h"

// Constructor for SetTaxCommand
// Initializes the command with the government object and the new tax rate
SetTaxCommand::SetTaxCommand(Government* gov, double rate) : government(gov), taxRate(rate) {}

SetTaxCommand::SetTaxCommand(Government* gov, TaxSystem* taxSys, double rate, char category)
    : government(gov), taxRate(rate), previousTaxRate(0) {
    // Initialize or use `taxSys` and `category` as needed.
}


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

// Gets the name of the command
std::string SetTaxCommand::getName() const {
    return "SetTaxCommand";
}

// Gets the description of the command
std::string SetTaxCommand::getDescription() const {
    return "Sets the tax rate in the government.";
}

// Checks if the command can be executed
bool SetTaxCommand::canExecute() const {
    return taxRate >= 0;
}

double SetTaxCommand::returnVal() {
    return taxRate;
}