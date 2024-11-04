/**
 * @file EnforcePolicyCommand.cpp
 * @brief Implementation of the EnforcePolicyCommand class for enforcing policies in the government.
 * 
 * This file contains the implementation of the EnforcePolicyCommand class, which provides
 * methods to enforce, undo, and validate policies in the government.
 * 
 * @version 1.0
 * @date 2023-10-01
 */

#include "EnforcePolicyCommand.h"
#include <stdexcept>

/**
 * @brief Constructor for EnforcePolicyCommand.
 * 
 * Initializes the command with the government object and the policy to enforce.
 * 
 * @param gov Pointer to the Government object.
 * @param pol The Policy to be enforced.
 */
EnforcePolicyCommand::EnforcePolicyCommand(Government* gov, Policy pol)
    : government(gov), policy(pol), isEnforced(false) {}

/**
 * @brief Executes the policy enforcement command.
 * 
 * Enforces the specified policy in the government.
 */
void EnforcePolicyCommand::execute() {
    government->enforcePolicy(policy);
    isEnforced = true;
}

/**
 * @brief Undoes the policy enforcement command.
 * 
 * Reverts the policy enforcement if applicable.
 */
void EnforcePolicyCommand::undo() {
    if (isEnforced) {
        // Implement undo logic if applicable
        isEnforced = false;
    }
}

/**
 * @brief Checks if the policy is enforced.
 * 
 * @return true if the policy is enforced, false otherwise.
 */
bool EnforcePolicyCommand::isPolicyEnforced() const {
    return isEnforced;
}

/**
 * @brief Sets the enforcement status of the policy.
 * 
 * @param enforced The enforcement status to be set.
 */
void EnforcePolicyCommand::setPolicyEnforced(bool enforced) {
    isEnforced = enforced;
}

/**
 * @brief Validates the policy enforcement.
 * 
 * Ensures the policy is valid for enforcement.
 * 
 * @return true if the policy is valid for enforcement, false otherwise.
 */
bool EnforcePolicyCommand::validateEnforcement() const {
    // Implement validation logic if applicable
    return true;
}

/**
 * @brief Executes the policy enforcement command with validation.
 * 
 * Throws an exception if the enforcement is invalid.
 */
void EnforcePolicyCommand::executeWithValidation() {
    if (!validateEnforcement()) {
        throw std::runtime_error("Invalid policy for enforcement");
    }
    execute();
}

/**
 * @brief Gets the name of the command.
 * 
 * @return The name of the command.
 */
std::string EnforcePolicyCommand::getName() const {
    return "EnforcePolicyCommand";
}

/**
 * @brief Gets the description of the command.
 * 
 * @return The description of the command.
 */
std::string EnforcePolicyCommand::getDescription() const {
    return "Enforces a policy in the government.";
}

/**
 * @brief Checks if the command can be executed.
 * 
 * @return true if the command can be executed, false otherwise.
 */
bool EnforcePolicyCommand::canExecute() const {
    return !isEnforced;
}

/**
 * @brief Returns an appropriate value based on the policy enforcement.
 * 
 * @return A double value based on the policy enforcement.
 */
double EnforcePolicyCommand::returnVal() {
    // Return an appropriate value based on the policy enforcement
    return 0.0;
}