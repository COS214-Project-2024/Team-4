#ifndef ALLOCATEBUDGETCOMMAND_H
#define ALLOCATEBUDGETCOMMAND_H

#include "GovCommand.h"
#include "Government.h"
#include "CityService.h"

class AllocateBudgetCommand : public GovCommand {

private:
    Government* government;
    CityService& service;
    double amount;
    double prevAllocation;

public:
    AllocateBudgetCommand(Government* gov, CityService& srv, double amt);

    void execute() override;
    void undo() override;
};

#endif