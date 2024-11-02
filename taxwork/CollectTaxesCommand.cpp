#include "CollectTaxesCommand.h"

CollectTaxesCommand::CollectTaxesCommand(std::shared_ptr<Building> building, std::shared_ptr<TaxType> taxType) {
	this->building = building;
	taxesCollected = 0;
	this->taxType = taxType;
}

void CollectTaxesCommand::execute() {
	taxesCollected = building->payTaxes(taxType.get());
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
