#ifndef PROPERTY_H
#define PROPERTY_H

#include "TaxType.h"
class Property : public TaxType {

private:
	double propertyTax;
	char cType;

public:
	Property(double rate, char type);
	void setTax(double rate);
	double calculateTax(double val) override;
};

#endif
