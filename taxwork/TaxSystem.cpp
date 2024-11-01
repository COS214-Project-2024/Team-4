#include "TaxSystem.h"


void TaxSystem::addCitizenTaxPayer(Citizen* taxPayer, char tType) {
this->citizenTaxPayers.insert(std::pair<Citizen*, char>(taxPayer, tType));

}

void TaxSystem::addBusinessTaxPayer(Business* bTaxPayer, char tType) {
	this->businessTaxPayers.insert(std::pair<Business*, char>(bTaxPayer, tType));	
}

void TaxSystem::removeCitizenTaxPayer(Citizen* taxPayer) {

this->citizenTaxPayers.erase(taxPayer);
}

void TaxSystem::removeBusinessTaxPayer(Business* bTaxPayer) {
this->businessTaxPayers.erase(bTaxPayer);
}

void TaxSystem::updateTaxRate(char cType, double rate) {
	taxRates.find(cType)->second->setTax(rate);
}

void TaxSystem::collectTaxes(Building* building,char taxType) {
 GovCommand* command = new CollectTaxesCommand(building, taxRates.find(taxType)->second->getTaxRate());
 command->execute();
 command->returnVal();
}

void TaxSystem::setTax(double rate, char taxType) {
	switch (taxType) {
		case 'I': {
			TaxType* tax = new Income(rate, taxType);
			this->taxRates.insert(std::pair<double, TaxType*>(rate, tax));
			break;
		}
		case 'P': {
			TaxType* tax = new Property(rate, taxType);
			this->taxRates.insert(std::pair<double, TaxType*>(rate, tax));
			break;
		}
		case 'S': {
			TaxType* tax = new Sales(rate, taxType);
			this->taxRates.insert(std::pair<double, TaxType*>(rate, tax));
			break;
		}
		default:
			break;
	}
}


void TaxSystem::checkImpact() {
  // TODO - implement TaxSystem::addTaxRate
	throw "Not yet implemented";
}
