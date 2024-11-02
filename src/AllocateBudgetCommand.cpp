#include "AllocateBudgetCommand.h"

// Constructor for AllocateBudgetCommand
// Initializes the command with the government, city service, and the amount to allocate
AllocateBudgetCommand::AllocateBudgetCommand(Government* gov, CityService& srv, double amt)
    : government(gov), service(srv), amount(amt), prevAllocation(0.0) {}

// Executes the budget allocation command
// Stores the previous allocation and allocates the new budget amount to the service
void AllocateBudgetCommand::execute() {
    prevAllocation = service.getBudgetAllocated();
    government->allocateBudget(service, amount);
}

// Undoes the budget allocation command
// Reverts the budget allocation to the previous state
void AllocateBudgetCommand::undo() {
    government->revertBudgetAllocation(service, amount);
}