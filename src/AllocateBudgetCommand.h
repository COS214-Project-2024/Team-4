#ifndef ALLOCATEBUDGETCOMMAND_H
#define ALLOCATEBUDGETCOMMAND_H

#include "GovCommand.h"
#include "Government.h"
#include "CityService.h"

// AllocateBudgetCommand class
// This class represents a command to allocate a budget to a city service
class AllocateBudgetCommand : public GovCommand {

private:
    Government* government; // Pointer to the government object
    CityService& service;   // Reference to the city service object
    double amount;          // Amount to allocate
    double prevAllocation;  // Previous allocation amount

public:
    // Constructor
    // Initializes the command with the government, city service, and the amount to allocate
    AllocateBudgetCommand(Government* gov, CityService& srv, double amt);

    // Executes the budget allocation command
    void execute() override;

    // Undoes the budget allocation command
    void undo() override;
};

#endif