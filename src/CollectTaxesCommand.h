/**
 * @file CollectTaxesCommand.h
 * @brief Declaration of the CollectTaxesCommand class.
 *
 * This file contains the declaration of the CollectTaxesCommand class which handles the collection of taxes.
 * 
 * @version 1.0
 */

#ifndef COLLECTTAXESCOMMAND_H
#define COLLECTTAXESCOMMAND_H

#include "GovCommand.h"
#include "Government.h"
#include "Building.h"
#include "TaxType.h"

/**
 * @brief CollectTaxesCommand class.
 *
 * This class represents a command to collect taxes from the government.
 */
class CollectTaxesCommand : public GovCommand {

private:
    Government* government;   ///< Pointer to the government object
    double collectedTaxes;    ///< Amount of taxes collected

    std::shared_ptr<Building> building; ///< Shared pointer to the Building object
    double taxesCollected;    ///< Amount of taxes collected from the building
    double taxRate;           ///< Tax rate for the collection
    TaxType* taxType;         ///< Pointer to the TaxType object

public:
    /**
     * @brief Constructor for CollectTaxesCommand.
     *
     * Initializes the command with the government object.
     * 
     * @param gov Pointer to the Government object.
     * @param building Shared pointer to the Building object.
     * @param taxType Pointer to the TaxType object.
     */
    CollectTaxesCommand(Government* gov, std::shared_ptr<Building> building, TaxType* taxType);

    /**
     * @brief Executes the tax collection command.
     */
    void execute() override;

    /**
     * @brief Undoes the tax collection command.
     */
    void undo() override;

    /**
     * @brief Gets the amount of taxes collected.
     * 
     * @return The amount of taxes collected.
     */
    double getCollectedTaxes() const;

    /**
     * @brief Sets the amount of taxes collected.
     * 
     * @param amount The amount of taxes collected.
     * @throws std::invalid_argument if the amount is negative.
     */
    void setCollectedTaxes(double amount);

    /**
     * @brief Validates the tax collection.
     *
     * Ensures the government has a valid tax rate.
     * 
     * @return True if the tax rate is valid, false otherwise.
     */
    bool validateCollection() const;

    /**
     * @brief Executes the tax collection command with validation.
     *
     * Throws an exception if the collection is invalid.
     * 
     * @throws std::runtime_error if the tax rate is invalid.
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
     * @return True if the command can be executed, false otherwise.
     */
    bool canExecute() const override;

    /**
     * @brief Gets the amount of taxes collected.
     * 
     * @return The amount of taxes collected.
     */
    double getTaxesCollected();

    /**
     * @brief Returns the amount of taxes collected.
     * 
     * @return The amount of taxes collected.
     */
    double returnVal();
};

#endif // COLLECTTAXESCOMMAND_H