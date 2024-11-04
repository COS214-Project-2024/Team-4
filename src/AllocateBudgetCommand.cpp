/**
 * @file AllocateBudgetCommand.cpp
 * @brief Implementation of the AllocateBudgetCommand class.
 * 
 * This file contains the implementation of the AllocateBudgetCommand class, which is used
 * to allocate a budget to a city service. It includes methods to execute, undo, and validate
 * the budget allocation, as well as getters and setters for the allocation amount and previous
 * allocation amount.
 * 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @note This file is part of a project for managing city budgets and services.
 */

#include "AllocateBudgetCommand.h"
#include <stdexcept>

/**
 * @brief Construct a new Allocate Budget Command object.
 * 
 * @param gov Pointer to the government object.
 * @param srv Reference to the city service object.
 * @param amt The amount to allocate.
 */
AllocateBudgetCommand::AllocateBudgetCommand(Government* gov, CityService& srv, double amt)
    : government(gov), service(srv), amount(amt), prevAllocation(0.0) {}

/**
 * @brief Executes the budget allocation command.
 * 
 * Stores the previous allocation and allocates the new budget amount to the service.
 */
void AllocateBudgetCommand::execute() {
    prevAllocation = service.getBudgetAllocated();
    government->allocateBudget(service, amount);
}

/**
 * @brief Undoes the budget allocation command.
 * 
 * Reverts the budget allocation to the previous state.
 */
void AllocateBudgetCommand::undo() {
    government->revertBudgetAllocation(service, amount);
}

/**
 * @brief Gets the amount to be allocated.
 * 
 * @return double The amount to be allocated.
 */
double AllocateBudgetCommand::getAmount() const {
    return amount;
}

/**
 * @brief Sets the amount to be allocated.
 * 
 * @param amt The amount to be allocated.
 * @throws std::invalid_argument if the amount is negative.
 */
void AllocateBudgetCommand::setAmount(double amt) {
    if (amt < 0) {
        throw std::invalid_argument("Amount cannot be negative");
    }
    amount = amt;
}

/**
 * @brief Gets the previous allocation amount.
 * 
 * @return double The previous allocation amount.
 */
double AllocateBudgetCommand::getPrevAllocation() const {
    return prevAllocation;
}

/**
 * @brief Sets the previous allocation amount.
 * 
 * @param prevAmt The previous allocation amount.
 * @throws std::invalid_argument if the previous allocation amount is negative.
 */
void AllocateBudgetCommand::setPrevAllocation(double prevAmt) {
    if (prevAmt < 0) {
        throw std::invalid_argument("Previous allocation cannot be negative");
    }
    prevAllocation = prevAmt;
}

/**
 * @brief Validates the budget allocation.
 * 
 * Ensures the government has enough budget to allocate.
 * 
 * @return true if the allocation is valid.
 * @return false if the allocation is invalid.
 */
bool AllocateBudgetCommand::validateAllocation() const {
    return government->getBudget() >= amount;
}

/**
 * @brief Executes the budget allocation command with validation.
 * 
 * Throws an exception if the allocation is invalid.
 * 
 * @throws std::runtime_error if the allocation is invalid.
 */
void AllocateBudgetCommand::executeWithValidation() {
    if (!validateAllocation()) {
        throw std::runtime_error("Insufficient budget for allocation");
    }
    execute();
}

/**
 * @brief Gets the name of the command.
 * 
 * @return std::string The name of the command.
 */
std::string AllocateBudgetCommand::getName() const {
    return "AllocateBudgetCommand";
}

/**
 * @brief Gets the description of the command.
 * 
 * @return std::string The description of the command.
 */
std::string AllocateBudgetCommand::getDescription() const {
    return "Allocates a budget to a city service.";
}

/**
 * @brief Checks if the command can be executed.
 * 
 * @return true if the command can be executed.
 * @return false if the command cannot be executed.
 */
bool AllocateBudgetCommand::canExecute() const {
    return validateAllocation();
}

/**
 * @brief Returns the amount to be allocated.
 * 
 * @return double The amount to be allocated.
 */
double AllocateBudgetCommand::returnVal() {
    return amount;
}