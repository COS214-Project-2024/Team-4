#include "SetTaxCommand.h"
#include "Government.h"
#include "TaxSystem.h"
#include <iostream>
#include "TaxType.h"
#include "VAT.h"
#include "Sales.h"
#include "Income.h"
#include "Property.h"

SetTaxCommand::SetTaxCommand(Government* gov, TaxSystem* taxSys, double rate, char taxType)
    : government(gov), taxSys(taxSys), taxRate(rate), taxType(taxType), previousTaxRate(0.0)  {



    if (taxType == 'I') {
        newTaxType = new Income(rate);
    } else if (taxType == 'P') {
        double propertyLevy = 0.5;  //  levy for property tax
        double additionalFees = 100.0; //  additional fees
        newTaxType = new Property(rate, propertyLevy, additionalFees);
    } else if (taxType == 'S') {
        double salesLevy = 2.0; //  environmental levy for sales tax
        double serviceFee = 15.0; //  service fee
        newTaxType = new Sales(rate, salesLevy, serviceFee);
    } else if (taxType == 'V') {
        newTaxType = new VAT(rate);
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