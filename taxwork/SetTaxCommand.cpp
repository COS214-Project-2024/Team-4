#include "SetTaxCommand.h"

SetTaxCommand::SetTaxCommand(Government* gov, double rate) : government(gov), taxRate(rate), previousTaxRate(0.0) {}

void SetTaxCommand::execute() {
    this->previousTaxRate = government->getTaxRate();
    government->setTax(taxRate);
}

void SetTaxCommand::undo() {
    government->setTax(previousTaxRate);
}

double SetTaxCommand::returnVal() {
    return previousTaxRate;
}