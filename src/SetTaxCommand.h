#ifndef SETTAXCOMMAND_H
#define SETTAXCOMMAND_H

/**
 * @file SetTaxCommand.h
 * @brief Declaration of the SetTaxCommand class.
 * 
 * This file contains the declaration of the SetTaxCommand class, which is used to set the tax rate in the government.
 * 
 * @version 1.0
 * @date 2023-10-05
 * 
 */

#include "GovCommand.h"
#include "Government.h"
#include "TaxSystem.h"

/**
 * @class SetTaxCommand
 * @brief A command to set the tax rate in the government.
 * 
 * This class represents a command to set the tax rate in the government.
 */
class SetTaxCommand : public GovCommand {

private:
    Government* government;   ///< Pointer to the government object
    double taxRate;           ///< New tax rate to be set
    double previousTaxRate;   ///< Previous tax rate to revert if needed

public:
    /**
     * @brief Constructor for SetTaxCommand.
     * 
     * Initializes the command with the government object and the new tax rate.
     * 
     * @param gov Pointer to the Government object.
     * @param rate The new tax rate to be set.
     */
    SetTaxCommand(Government* gov, double rate);

    /**
     * @brief Constructor for SetTaxCommand with additional parameters.
     * 
     * Initializes the command with the government object, tax system, new tax rate, and category.
     * 
     * @param gov Pointer to the Government object.
     * @param taxSys Pointer to the TaxSystem object.
     * @param rate The new tax rate to be set.
     * @param category The category of the tax.
     */
    SetTaxCommand(Government* gov, TaxSystem* taxSys, double rate, char category);

    /**
     * @brief Executes the set tax command.
     * 
     * Stores the previous tax rate and sets the new tax rate.
     */
    void execute() override;

    /**
     * @brief Undoes the set tax command.
     * 
     * Reverts the tax rate to the previous rate.
     */
    void undo() override;

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
     * @brief Returns the tax rate.
     * 
     * @return The tax rate.
     */
    double returnVal() override;

    /**
     * @brief Checks if the command can be executed.
     * 
     * @return True if the command can be executed, false otherwise.
     */
    bool canExecute() const override;
};

#endif // SETTAXCOMMAND_H