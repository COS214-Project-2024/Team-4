#include "CollectTaxesCommand.h"
#include <stdexcept>

// Constructor for CollectTaxesCommand
// Initializes the command with the government object
CollectTaxesCommand::CollectTaxesCommand(Government* gov)
    : government(gov), collectedTaxes(0.0) {}

// Executes the tax collection command
// Collects taxes from the government and stores the collected amount
void CollectTaxesCommand::execute() {
    collectedTaxes = government->collectTaxes();
}

// Undoes the tax collection command
// Refunds the collected taxes to the government
void CollectTaxesCommand::undo() {
    government->refundTaxes(collectedTaxes);
}

// Gets the amount of taxes collected
double CollectTaxesCommand::getCollectedTaxes() const {
    return collectedTaxes;
}

// Sets the amount of taxes collected
void CollectTaxesCommand::setCollectedTaxes(double amount) {
    if (amount < 0) {
        throw std::invalid_argument("Collected taxes cannot be negative");
    }
    collectedTaxes = amount;
}

// Validates the tax collection
// Ensures the government has a valid tax rate
bool CollectTaxesCommand::validateCollection() const {
    return government->getTaxRate() > 0;
}

// Executes the tax collection command with validation
// Throws an exception if the collection is invalid
void CollectTaxesCommand::executeWithValidation() {
    if (!validateCollection()) {
        throw std::runtime_error("Invalid tax rate for collection");
    }
    execute();
}

// Gets the name of the command
std::string CollectTaxesCommand::getName() const {
    return "CollectTaxesCommand";
}

// Gets the description of the command
std::string CollectTaxesCommand::getDescription() const {
    return "Collects taxes from the government.";
}

// Checks if the command can be executed
bool CollectTaxesCommand::canExecute() const {
    return validateCollection();
}