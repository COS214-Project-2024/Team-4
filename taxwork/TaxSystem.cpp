#include "TaxSystem.h"
#include "CollectTaxesCommand.h"
#include "SetTaxCommand.h"

void TaxSystem::addIncomeTaxBuilding(Building* building) {
	if(building->getType() == "Residential"){
		incomeTaxbuildings.push_back(building);
	}else if (building->getType() == "Commercial")
	{
		incomeTaxbuildings.push_back(building);
	} else if (building->getType() == "Industrial")
	{
		incomeTaxbuildings.push_back(building);
	
	} else if (building->getType() == "Government")
	{
		std::cout<<"Government building does not collect taxes"<<std::endl;
	} else
	{
		std::cout<<"Building type cannot be taxed"<<std::endl;
	}
}

void TaxSystem::addPropertyTaxBuilding(Building* building) {
	if(building->getType() == "Residential"){
		propertyTaxbuildings.push_back(building);
	}else if (building->getType() == "Commercial")
	{
		propertyTaxbuildings.push_back(building);
	} else if (building->getType() == "Industrial")
	{
		propertyTaxbuildings.push_back(building);
	
	} else if (building->getType() == "Government")
	{
		std::cout<<"Government building does not collect taxes"<<std::endl;
	} else
	{
		std::cout<<"Building type cannot be taxed"<<std::endl;
	}
}

void TaxSystem::addSalesTaxBuilding(Building* building) {
if(building->getType() == "Residential"){
	std::cout<<"Residential building does not collect taxes for sales"<<std::endl;
	}else if (building->getType() == "Commercial")
	{
		salesTaxbuildings.push_back(building);
	} else if (building->getType() == "Industrial")
	{
		salesTaxbuildings.push_back(building);
	
	} else if (building->getType() == "Government")
	{
		std::cout<<"Government building does not collect taxes for sales"<<std::endl;
	} else
	{
		std::cout<<"Building type cannot be taxed"<<std::endl;
	}
}
void TaxSystem::addVATTaxPayer(Citizen* citizen) {
	vatTaxpayers.push_back(citizen);
}

void TaxSystem::removeIncomeTaxBuilding(Building* building) {
	if(building->getType() == "Residential"){
		incomeTaxbuildings.erase(std::remove(incomeTaxbuildings.begin(), incomeTaxbuildings.end(), building), incomeTaxbuildings.end());
	}else if (building->getType() == "Commercial")
	{
		incomeTaxbuildings.erase(std::remove(incomeTaxbuildings.begin(), incomeTaxbuildings.end(), building), incomeTaxbuildings.end());
	} else if (building->getType() == "Industrial")
	{
		incomeTaxbuildings.erase(std::remove(incomeTaxbuildings.begin(), incomeTaxbuildings.end(), building), incomeTaxbuildings.end());
	
	} else if (building->getType() == "Government")
	{
		std::cout<<"Government building does not collect taxes"<<std::endl;
	} else
	{
		std::cout<<"Building type cannot be taxed"<<std::endl;
	}
}

void TaxSystem::removePropertyTaxBuilding(Building* building) {
	if(building->getType() == "Residential"){
		propertyTaxbuildings.erase(std::remove(propertyTaxbuildings.begin(), propertyTaxbuildings.end(), building), propertyTaxbuildings.end());
	}else if (building->getType() == "Commercial")
	{
		propertyTaxbuildings.erase(std::remove(propertyTaxbuildings.begin(), propertyTaxbuildings.end(), building), propertyTaxbuildings.end());
	} else if (building->getType() == "Industrial")
	{
		propertyTaxbuildings.erase(std::remove(propertyTaxbuildings.begin(), propertyTaxbuildings.end(), building), propertyTaxbuildings.end());
	
	} else if (building->getType() == "Government")
	{
		std::cout<<"Government building does not collect taxes"<<std::endl;
	} else
	{
		std::cout<<"Building type cannot be taxed"<<std::endl;
	}
}

void TaxSystem::removeSalesTaxBuilding(Building* building) {
	if(building->getType() == "Residential"){
		std::cout<<"Residential building does not collect taxes for sales"<<std::endl;
	}else if (building->getType() == "Commercial")
	{
		salesTaxbuildings.erase(std::remove(salesTaxbuildings.begin(), salesTaxbuildings.end(), building), salesTaxbuildings.end());
	} else if (building->getType() == "Industrial")
	{
		salesTaxbuildings.erase(std::remove(salesTaxbuildings.begin(), salesTaxbuildings.end(), building), salesTaxbuildings.end());
	
	} else if (building->getType() == "Government")
	{
		std::cout<<"Government building does not collect taxes for sales"<<std::endl;
	} else
	{
		std::cout<<"Building type cannot be taxed"<<std::endl;
	}
}


void TaxSystem::removeVATTaxPayer(Citizen* citizen) {
	vatTaxpayers.erase(std::remove(vatTaxpayers.begin(), vatTaxpayers.end(), citizen), vatTaxpayers.end());
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
	GovCommand* setTaxCommand = new SetTaxCommand(rate, taxType);
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

void TaxSystem::addTaxRate(TaxType* tax) {
  taxRates.insert(std::pair<double, TaxType*>(tax->getTaxRate(), tax));
}