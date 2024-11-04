/**
 * @file CollectTaxesCommand.cpp
 * @brief Implementation of the CollectTaxesCommand class.
 *
 * This file contains the implementation of the CollectTaxesCommand class which handles the collection of taxes.
 * 
 * @version 1.0
 */

#include "CollectTaxesCommand.h"
#include <stdexcept>
#include <iostream>

/**
 * @brief Constructor for CollectTaxesCommand.
 *
 * Initializes the command with the government object.
 * 
 * @param gov Pointer to the Government object.
 * @param building Shared pointer to the Building object.
 * @param taxType Pointer to the TaxType object.
 */
CollectTaxesCommand::CollectTaxesCommand(Government* gov, std::shared_ptr<Building> building, TaxType* taxType)
    : government(gov), collectedTaxes(0.0), taxType(taxType) {
    this->building = building;
}

/**
 * @brief Executes the tax collection command.
 *
 * Collects taxes from the government and stores the collected amount.
 */
void CollectTaxesCommand::execute() {
    collectedTaxes = government->collectTaxes();
    taxesCollected = building->payTaxes(taxType);
    std::cout << "Total taxes collected by CollectTaxesCommand: R" << taxesCollected << "\n";
}

/**
 * @brief Undoes the tax collection command.
 *
 * Refunds the collected taxes to the government.
 */
void CollectTaxesCommand::undo() {
    government->refundTaxes(collectedTaxes);
}

/**
 * @brief Gets the amount of taxes collected.
 * 
 * @return The amount of taxes collected.
 */
double CollectTaxesCommand::getCollectedTaxes() const {
    return collectedTaxes;
}

/**
 * @brief Sets the amount of taxes collected.
 * 
 * @param amount The amount of taxes collected.
 * @throws std::invalid_argument if the amount is negative.
 */
void CollectTaxesCommand::setCollectedTaxes(double amount) {
    if (amount < 0) {
        throw std::invalid_argument("Collected taxes cannot be negative");
    }
    collectedTaxes = amount;
}

/**
 * @brief Validates the tax collection.
 *
 * Ensures the government has a valid tax rate.
 * 
 * @return True if the tax rate is valid, false otherwise.
 */
bool CollectTaxesCommand::validateCollection() const {
    return government->getTaxRate() > 0;
}

/**
 * @brief Executes the tax collection command with validation.
 *
 * Throws an exception if the collection is invalid.
 * 
 * @throws std::runtime_error if the tax rate is invalid.
 */
void CollectTaxesCommand::executeWithValidation() {
    if (!validateCollection()) {
        throw std::runtime_error("Invalid tax rate for collection");
    }
    execute();
}

/**
 * @brief Gets the name of the command.
 * 
 * @return The name of the command.
 */
std::string CollectTaxesCommand::getName() const {
    return "CollectTaxesCommand";
}

/**
 * @brief Gets the description of the command.
 * 
 * @return The description of the command.
 */
std::string CollectTaxesCommand::getDescription() const {
    return "Collects taxes from the government.";
}

/**
 * @brief Checks if the command can be executed.
 * 
 * @return True if the command can be executed, false otherwise.
 */
bool CollectTaxesCommand::canExecute() const {
    return validateCollection();
}

/**
 * @brief Gets the amount of taxes collected.
 * 
 * @return The amount of taxes collected.
 */
double CollectTaxesCommand::getTaxesCollected() {
    return taxesCollected;
}

/**
 * @brief Returns the amount of taxes collected.
 * 
 * @return The amount of taxes collected.
 */
double CollectTaxesCommand::returnVal() {
    return taxesCollected;
}