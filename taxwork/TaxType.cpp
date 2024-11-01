#include "TaxType.h"

TaxType::TaxType(double rate, char type) {
this->taxRate = rate;
this->cType = type;
}

double TaxType::calculateTax(double val) {
return val * taxRate;
}

void TaxType::setTax(double rate) {
	this->taxRate = rate;
}

double TaxType::getTaxRate() {
	return taxRate;
}
