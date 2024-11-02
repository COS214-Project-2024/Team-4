#include "SetTaxCommand.h"
#include "Government.h"
#include "TaxSystem.h"
#include <iostream>
#include "TaxType.h"
SetTaxCommand::SetTaxCommand(Government* gov, TaxSystem* taxSys, double rate,char taxType) : government(gov), taxRate(rate), previousTaxRate(0.0), taxSys(taxSys), taxType(taxType) {
    if(taxType == 'I'){
        taxSys->addTaxRate(new Income(rate, taxType));
    }else if (taxType == 'P')
    {
        taxSys->addTaxRate(new Property(rate, taxType));
    } else if (taxType == 'S')
    {
        taxSys->addTaxRate(new Sales(rate, taxType));
    }else if(taxType == 'V'){
       taxSys->addTaxRate(new VAT(rate, taxType));
    }else{
        std::cout<<"Invalid tax type"<<std::endl;
    }
}

void SetTaxCommand::execute() {
    // this->previousTaxRate = government->getTaxRate();
    // government->setTax(taxRate);
    taxSys->addTaxRate(taxType);



}

void SetTaxCommand::undo() {
    government->setTax(previousTaxRate);
}

double SetTaxCommand::returnVal() {
    return previousTaxRate;
}