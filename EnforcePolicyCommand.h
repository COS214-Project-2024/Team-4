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

public:
    // Constructor
    // Initializes the command with the government object and the policy to enforce
    EnforcePolicyCommand(Government* gov, Policy pol);

    // Executes the policy enforcement command
    void execute() override;

    // Undoes the policy enforcement command
    void undo() override;
};

#endif