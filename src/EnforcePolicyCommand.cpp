#include "EnforcePolicyCommand.h"

// Constructor for EnforcePolicyCommand
// Initializes the command with the government object and the policy to enforce
EnforcePolicyCommand::EnforcePolicyCommand(Government* gov, Policy pol)
    : government(gov), policy(pol) {}

// Executes the policy enforcement command
// Enforces the specified policy in the government
void EnforcePolicyCommand::execute() {
    government->enforcePolicy(policy);
}

// Undoes the policy enforcement command
// Reverts the policy enforcement if applicable
void EnforcePolicyCommand::undo() {
    // Implement undo logic if applicable
}