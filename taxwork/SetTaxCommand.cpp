// SetTaxCommand.cpp

#include "SetTaxCommand.h"
#include "Government.h"
#include "TaxSystem.h"
#include <iostream>
#include "TaxType.h"
#include "VAT.h"
#include "Income.h"
#include "Property.h"
#include "Sales.h"

SetTaxCommand::SetTaxCommand(std::shared_ptr<Government> gov, std::shared_ptr<TaxSystem> taxSys, double rate, char taxType)
    : government(gov), taxSys(taxSys), taxRate(rate), taxType(taxType), previousTaxRate(0.0) {

    if (taxType == 'I') {
        newTaxType = std::make_shared<Income>(rate);
    } else if (taxType == 'P') {
        double propertyLevy = 0.5;  // levy for property tax
        double additionalFees = 100.0; // additional fees
        newTaxType = std::make_shared<Property>(rate, propertyLevy, additionalFees);
    } else if (taxType == 'S') {
        double salesLevy = 2.0; // environmental levy for sales tax
        double serviceFee = 15.0; // service fee
        newTaxType = std::make_shared<Sales>(rate, salesLevy, serviceFee);
    } else if (taxType == 'V') {
        newTaxType = std::make_shared<VAT>(rate);
    } else {
        std::cout << "Invalid tax type" << std::endl;
        return; // Exit if tax type is invalid
    }
}

void SetTaxCommand::execute() {
    // Add the tax rate to the tax system
    taxSys->addTaxRate(newTaxType);
}

void SetTaxCommand::undo() {
    // Remove the tax rate from the tax system
    taxSys->removeTaxRate(newTaxType);
    government->setTax(previousTaxRate);
}

double SetTaxCommand::returnVal() {
    return newTaxType->getTaxRate();
}