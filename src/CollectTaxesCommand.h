#ifndef COLLECTTAXESCOMMAND_H
#define COLLECTTAXESCOMMAND_H

#include "GovCommand.h"
#include "Government.h"
#include "Building.h"
#include "TaxType.h"


// CollectTaxesCommand class
// This class represents a command to collect taxes from the government
class CollectTaxesCommand : public GovCommand {

private:
    Government* government;   // Pointer to the government object
    double collectedTaxes;    // Amount of taxes collected

    Building* building;
	double taxesCollected;
	double taxRate;
	TaxType* taxType;

public:
    // Constructor
    // Initializes the command with the government object
    CollectTaxesCommand(Government* gov,Building* building, TaxType* taxType);

    // Executes the tax collection command
    void execute() override;

    // Undoes the tax collection command
    void undo() override;

    // Gets the amount of taxes collected
    double getCollectedTaxes() const;

    // Sets the amount of taxes collected
    void setCollectedTaxes(double amount);

    // Validates the tax collection
    bool validateCollection() const;

    // Executes the tax collection command with validation
    void executeWithValidation();

    // Gets the name of the command
    std::string getName() const override;

    // Gets the description of the command
    std::string getDescription() const override;

    // Checks if the command can be executed
    bool canExecute() const override;

	double getTaxesCollected();
    
	double returnVal();
};

#endif