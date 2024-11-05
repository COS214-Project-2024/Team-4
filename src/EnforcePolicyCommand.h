#ifndef ENFORCEPOLICYCOMMAND_H
#define ENFORCEPOLICYCOMMAND_H

#include "GovCommand.h"
#include "Government.h"
#include "Policy.h"

/**
 * @file EnforcePolicyCommand.h
 * @brief Declaration of the EnforcePolicyCommand class for enforcing policies in the government.
 * 
 * This file contains the declaration of the EnforcePolicyCommand class, which provides
 * methods to enforce, undo, and validate policies in the government.
 * 
 * @version 1.0
 * @date 2024-11-04
 */

/**
 * @class EnforcePolicyCommand
 * @brief The EnforcePolicyCommand class for enforcing policies in the government.
 * 
 * This class represents a command to enforce a policy in the government.
 */
class EnforcePolicyCommand : public GovCommand {

private:
    Government* government; /**< Pointer to the government object */
    Policy policy;          /**< Policy to be enforced */
    bool isEnforced;        /**< Flag to check if the policy is enforced */

public:
    /**
     * @brief Constructor for EnforcePolicyCommand.
     * 
     * Initializes the command with the government object and the policy to enforce.
     * 
     * @param gov Pointer to the Government object.
     * @param pol The Policy to be enforced.
     */
    EnforcePolicyCommand(Government* gov, Policy pol);

    /**
     * @brief Executes the policy enforcement command.
     * 
     * Enforces the specified policy in the government.
     */
    void execute() override;

    /**
     * @brief Undoes the policy enforcement command.
     * 
     * Reverts the policy enforcement if applicable.
     */
    void undo() override;

    /**
     * @brief Checks if the policy is enforced.
     * 
     * @return true if the policy is enforced, false otherwise.
     */
    bool isPolicyEnforced() const;

    /**
     * @brief Sets the enforcement status of the policy.
     * 
     * @param enforced The enforcement status to be set.
     */
    void setPolicyEnforced(bool enforced);

    /**
     * @brief Validates the policy enforcement.
     * 
     * Ensures the policy is valid for enforcement.
     * 
     * @return true if the policy is valid for enforcement, false otherwise.
     */
    bool validateEnforcement() const;

    /**
     * @brief Executes the policy enforcement command with validation.
     * 
     * Throws an exception if the enforcement is invalid.
     */
    void executeWithValidation();

    /**
     * @brief Gets the name of the command.
     * 
     * @return The name of the command.
     */
    std::string getName() const override;

    /**
     * @brief Gets the description of the command.
     * 
     * @return The description of the command.
     */
    std::string getDescription() const override;

    /**
     * @brief Checks if the command can be executed.
     * 
     * @return true if the command can be executed, false otherwise.
     */
    bool canExecute() const override;

    /**
     * @brief Returns an appropriate value based on the policy enforcement.
     * 
     * @return A double value based on the policy enforcement.
     */
    double returnVal() override;
};

#endif // ENFORCEPOLICYCOMMAND_H