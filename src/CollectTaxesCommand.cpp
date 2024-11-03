#include "CollectTaxesCommand.h"

CollectTaxesCommand::CollectTaxesCommand(Building* building, TaxType* taxType) {
	this->building = building;
	taxesCollected = 0;
	this->taxType = taxType;
}

void CollectTaxesCommand::execute() {
    taxesCollected = building->payTaxes(taxType);
    std::cout << "Total taxes collected by CollectTaxesCommand: $" << taxesCollected << "\n";
}


void CollectTaxesCommand::undo() {
	building->undoCollectTaxes();
}
double CollectTaxesCommand::getTaxesCollected() {
	return taxesCollected;
}

double CollectTaxesCommand::returnVal() {
	return taxesCollected;
}
