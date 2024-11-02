#include "CollectTaxesCommand.h"

CollectTaxesCommand::CollectTaxesCommand(Building* building, double taxRate) {
	this->building = building;
	taxesCollected = 0;
	this->taxRate = taxRate;

}

void CollectTaxesCommand::execute() {
	taxesCollected = building->collectTaxes();
}

void CollectTaxesCommand::undo() {
	building->undoCollectIncome();
}
double CollectTaxesCommand::getTaxesCollected() {
	return taxesCollected;
}

double CollectTaxesCommand::returnVal() {
	return taxesCollected;
}
