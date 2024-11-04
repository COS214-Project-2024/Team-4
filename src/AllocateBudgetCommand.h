/**
 * @file AllocateBudgetCommand.h
 * @brief Definition of the AllocateBudgetCommand class.
 * 
 * This file contains the definition of the AllocateBudgetCommand class, which is used
 * to allocate a budget to a city service. It includes methods to execute, undo, and validate
 * the budget allocation, as well as getters and setters for the allocation amount and previous
 * allocation amount.
 * 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @note This file is part of a project for managing city budgets and services.
 */

#ifndef ALLOCATEBUDGETCOMMAND_H
#define ALLOCATEBUDGETCOMMAND_H

#include "GovCommand.h"
#include "Government.h"
#include "CityService.h"

/**
 * @class AllocateBudgetCommand
 * @brief Represents a command to allocate a budget to a city service.
 * 
 * This class is used to allocate a budget to a city service. It includes methods to execute,
 * undo, and validate the budget allocation, as well as getters and setters for the allocation
 * amount and previous allocation amount.
 */
class AllocateBudgetCommand : public GovCommand {

private:
    Government* government; ///< Pointer to the government object
    CityService& service;   ///< Reference to the city service object
    double amount;          ///< Amount to allocate
    double prevAllocation;  ///< Previous allocation amount

public:
    /**
     * @brief Construct a new Allocate Budget Command object.
     * 
     * @param gov Pointer to the government object.
     * @param srv Reference to the city service object.
     * @param amt The amount to allocate.
     */
    AllocateBudgetCommand(Government* gov, CityService& srv, double amt);

    /**
     * @brief Executes the budget allocation command.
     * 
     * Stores the previous allocation and allocates the new budget amount to the service.
     */
    void execute() override;

    /**
     * @brief Undoes the budget allocation command.
     * 
     * Reverts the budget allocation to the previous state.
     */
    void undo() override;

    /**
     * @brief Gets the amount to be allocated.
     * 
     * @return double The amount to be allocated.
     */
    double getAmount() const;

    /**
     * @brief Sets the amount to be allocated.
     * 
     * @param amt The amount to be allocated.
     * @throws std::invalid_argument if the amount is negative.
     */
    void setAmount(double amt);

    /**
     * @brief Gets the previous allocation amount.
     * 
     * @return double The previous allocation amount.
     */
    double getPrevAllocation() const;

    /**
     * @brief Sets the previous allocation amount.
     * 
     * @param prevAmt The previous allocation amount.
     * @throws std::invalid_argument if the previous allocation amount is negative.
     */
    void setPrevAllocation(double prevAmt);

    /**
     * @brief Validates the budget allocation.
     * 
     * Ensures the government has enough budget to allocate.
     * 
     * @return true if the allocation is valid.
     * @return false if the allocation is invalid.
     */
    bool validateAllocation() const;

    /**
     * @brief Executes the budget allocation command with validation.
     * 
     * Throws an exception if the allocation is invalid.
     * 
     * @throws std::runtime_error if the allocation is invalid.
     */
    void executeWithValidation();

    /**
     * @brief Gets the name of the command.
     * 
     * @return std::string The name of the command.
     */
    std::string getName() const override;

    /**
     * @brief Gets the description of the command.
     * 
     * @return std::string The description of the command.
     */
    std::string getDescription() const override;

    /**
     * @brief Checks if the command can be executed.
     * 
     * @return true if the command can be executed.
     * @return false if the command cannot be executed.
     */
    bool canExecute() const override;

    /**
     * @brief Returns the amount to be allocated.
     * 
     * @return double The amount to be allocated.
     */
    double returnVal() override;
};

#endif // ALLOCATEBUDGETCOMMAND_H