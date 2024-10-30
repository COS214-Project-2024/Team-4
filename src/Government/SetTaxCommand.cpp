#include "SetTaxCommand.h"

SetTaxCommand::SetTaxCommand(Government* gov, double rate) : government(gov), taxRate(rate) {}

void SetTaxCommand::execute() {
    previousTaxRate = government->getTaxRate();
    government->setTax(taxRate);
}

void SetTaxCommand::undo() {
    government->setTax(previousTaxRate);
}