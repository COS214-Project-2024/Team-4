#include "Sales.h"

Sales::Sales(double rate, char type):TaxType(rate,type) {
	this->SalesTax = rate;
	this->cType = type;
}

void Sales::setTax(double rate) {
	this->SalesTax = rate;
}

double Sales::calculateTax(double val) {
	return val * (SalesTax / 100.0);
}

