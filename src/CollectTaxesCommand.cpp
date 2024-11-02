#include "CollectTaxesCommand.h"

CollectTaxesCommand::CollectTaxesCommand(Government* gov)
    : government(gov), collectedTaxes(0.0) {}

void CollectTaxesCommand::execute() {
    collectedTaxes = government->collectTaxes();
}

void CollectTaxesCommand::undo() {
    government->refundTaxes(collectedTaxes);
}