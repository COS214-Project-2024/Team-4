#include "CollectTaxesCommand.h"

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