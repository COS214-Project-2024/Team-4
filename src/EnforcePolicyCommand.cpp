#include "EnforcePolicyCommand.h"
#include <stdexcept>

// Constructor for EnforcePolicyCommand
// Initializes the command with the government object and the policy to enforce
EnforcePolicyCommand::EnforcePolicyCommand(Government* gov, Policy pol)
    : government(gov), policy(pol), isEnforced(false) {}

// Executes the policy enforcement command
// Enforces the specified policy in the government
void EnforcePolicyCommand::execute() {
    government->enforcePolicy(policy);
    isEnforced = true;
}

// Undoes the policy enforcement command
// Reverts the policy enforcement if applicable
void EnforcePolicyCommand::undo() {
    if (isEnforced) {
        // Implement undo logic if applicable
        isEnforced = false;
    }
}

// Checks if the policy is enforced
bool EnforcePolicyCommand::isPolicyEnforced() const {
    return isEnforced;
}

// Sets the enforcement status of the policy
void EnforcePolicyCommand::setPolicyEnforced(bool enforced) {
    isEnforced = enforced;
}

// Validates the policy enforcement
// Ensures the policy is valid for enforcement
bool EnforcePolicyCommand::validateEnforcement() const {
    // Implement validation logic if applicable
    return true;
}

// Executes the policy enforcement command with validation
// Throws an exception if the enforcement is invalid
void EnforcePolicyCommand::executeWithValidation() {
    if (!validateEnforcement()) {
        throw std::runtime_error("Invalid policy for enforcement");
    }
    execute();
}

// Gets the name of the command
std::string EnforcePolicyCommand::getName() const {
    return "EnforcePolicyCommand";
}

// Gets the description of the command
std::string EnforcePolicyCommand::getDescription() const {
    return "Enforces a policy in the government.";
}

// Checks if the command can be executed
bool EnforcePolicyCommand::canExecute() const {
    return !isEnforced;
}

double EnforcePolicyCommand::returnVal() {
    // Return an appropriate value based on the policy enforcement
    return 0.0;
}