#include "AllocateBudgetCommand.h"

AllocateBudgetCommand::AllocateBudgetCommand(Government* gov, CityService& srv, double amt)
    : government(gov), service(srv), amount(amt), prevAllocation(0.0) {}

void AllocateBudgetCommand::execute() {
    prevAllocation = service.getBudgetAllocated();
    government->allocateBudget(service, amount);
}

void AllocateBudgetCommand::undo() {
    government->revertBudgetAllocation(service, amount);
}