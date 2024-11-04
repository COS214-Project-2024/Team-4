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

    // Gets the amount to be allocated
    double getAmount() const;

    // Sets the amount to be allocated
    void setAmount(double amt);

    // Gets the previous allocation amount
    double getPrevAllocation() const;

    // Sets the previous allocation amount
    void setPrevAllocation(double prevAmt);

    // Validates the budget allocation
    bool validateAllocation() const;

    // Executes the budget allocation command with validation
    void executeWithValidation();

    // Gets the name of the command
    std::string getName() const override;

    // Gets the description of the command
    std::string getDescription() const override;

    // Checks if the command can be executed
    bool canExecute() const override;

    double returnVal() override;
};

#endif