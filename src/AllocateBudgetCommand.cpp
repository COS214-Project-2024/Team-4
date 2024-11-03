#include "AllocateBudgetCommand.h"
#include <stdexcept>

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

// Gets the amount to be allocated
double AllocateBudgetCommand::getAmount() const {
    return amount;
}

// Sets the amount to be allocated
void AllocateBudgetCommand::setAmount(double amt) {
    if (amt < 0) {
        throw std::invalid_argument("Amount cannot be negative");
    }
    amount = amt;
}

// Gets the previous allocation amount
double AllocateBudgetCommand::getPrevAllocation() const {
    return prevAllocation;
}

// Sets the previous allocation amount
void AllocateBudgetCommand::setPrevAllocation(double prevAmt) {
    if (prevAmt < 0) {
        throw std::invalid_argument("Previous allocation cannot be negative");
    }
    prevAllocation = prevAmt;
}

// Validates the budget allocation
// Ensures the government has enough budget to allocate
bool AllocateBudgetCommand::validateAllocation() const {
    return government->getBudget() >= amount;
}

// Executes the budget allocation command with validation
// Throws an exception if the allocation is invalid
void AllocateBudgetCommand::executeWithValidation() {
    if (!validateAllocation()) {
        throw std::runtime_error("Insufficient budget for allocation");
    }
    execute();
}

