#include "Property.h"

Property::Property(double rate, char type):TaxType(rate,type) {
	this->propertyTax = rate;
	this->cType = type;
}

void Property::setTax(double rate) {
	this->propertyTax = rate;
}

double Property::calculateTax(double val) {
	return val * (propertyTax / 100.0);
}