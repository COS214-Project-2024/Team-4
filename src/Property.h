#ifndef PROPERTY_H
#define PROPERTY_H

#include "TaxType.h"
class Property : public TaxType {

private:
	double propertyTax;
	char cType;

public:
	void setTax(double rate);

	void calculateTax();
};

#endif
