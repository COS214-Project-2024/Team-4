#ifndef ENFORCEPOLICYCOMMAND_H
#define ENFORCEPOLICYCOMMAND_H

#include "GovCommand.h"
#include "Government.h"
#include "Policy.h"

// EnforcePolicyCommand class
// This class represents a command to enforce a policy in the government
class EnforcePolicyCommand : public GovCommand {

private:
    Government* government; // Pointer to the government object
    Policy policy;          // Policy to be enforced
    bool isEnforced;        // Flag to check if the policy is enforced

public:
    // Constructor
    // Initializes the command with the government object and the policy to enforce
    EnforcePolicyCommand(Government* gov, Policy pol);

    // Executes the policy enforcement command
    void execute() override;

    // Undoes the policy enforcement command
    void undo() override;

    // Checks if the policy is enforced
    bool isPolicyEnforced() const;

    // Sets the enforcement status of the policy
    void setPolicyEnforced(bool enforced);

    // Validates the policy enforcement
    bool validateEnforcement() const;

    // Executes the policy enforcement command with validation
    void executeWithValidation();

    // Gets the name of the command
    std::string getName() const override;

    // Gets the description of the command
    std::string getDescription() const override;

    // Checks if the command can be executed
    bool canExecute() const override;
};

#endif