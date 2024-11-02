// SetTaxCommand.h

#ifndef SETTAXCOMMAND_H
#define SETTAXCOMMAND_H

#include <memory>
#include "GovCommand.h"
#include "Government.h"
#include "TaxSystem.h"
#include "TaxType.h"

class SetTaxCommand : public GovCommand {
public:
    SetTaxCommand(std::shared_ptr<Government> gov, std::shared_ptr<TaxSystem> taxSys, double rate, char taxType);
    void execute() override;
    void undo() override;
    double returnVal() override;

private:
    std::shared_ptr<Government> government;
    std::shared_ptr<TaxSystem> taxSys;
    double taxRate;
    char taxType;
    double previousTaxRate;
    std::shared_ptr<TaxType> newTaxType;
};

#endif // SETTAXCOMMAND_H