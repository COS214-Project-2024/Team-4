/**
 * @file SetTaxCommand.cpp
 * @brief Implementation of the SetTaxCommand class.
 * 
 * This file contains the implementation of the SetTaxCommand class, which is used to set the tax rate in the government.
 * 
 * @version 1.0
 * @date 2023-10-05
 * 
 */

#include "SetTaxCommand.h"

/**
 * @brief Constructor for SetTaxCommand.
 * 
 * Initializes the command with the government object and the new tax rate.
 * 
 * @param gov Pointer to the Government object.
 * @param rate The new tax rate to be set.
 */
SetTaxCommand::SetTaxCommand(Government* gov, double rate) : government(gov), taxRate(rate) {}

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
SetTaxCommand::SetTaxCommand(Government* gov, TaxSystem* taxSys, double rate, char category)
    : government(gov), taxRate(rate), previousTaxRate(0) {
    // Initialize or use `taxSys` and `category` as needed.
}

/**
 * @brief Executes the set tax command.
 * 
 * Stores the previous tax rate and sets the new tax rate.
 */
void SetTaxCommand::execute() {
    previousTaxRate = government->getTaxRate();
    government->setTax(taxRate);
}

/**
 * @brief Undoes the set tax command.
 * 
 * Reverts the tax rate to the previous rate.
 */
void SetTaxCommand::undo() {
    government->setTax(previousTaxRate);
}

/**
 * @brief Gets the name of the command.
 * 
 * @return The name of the command.
 */
std::string SetTaxCommand::getName() const {
    return "SetTaxCommand";
}

/**
 * @brief Gets the description of the command.
 * 
 * @return The description of the command.
 */
std::string SetTaxCommand::getDescription() const {
    return "Sets the tax rate in the government.";
}

/**
 * @brief Checks if the command can be executed.
 * 
 * @return True if the command can be executed, false otherwise.
 */
bool SetTaxCommand::canExecute() const {
    return taxRate >= 0;
}

/**
 * @brief Returns the tax rate.
 * 
 * @return The tax rate.
 */
double SetTaxCommand::returnVal() {
    return taxRate;
}