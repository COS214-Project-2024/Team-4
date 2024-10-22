#ifndef INCOME_H
#define INCOME_H

#include "TaxType.h"

class Income : TaxType {

private:
	double incomeTax;
	char cType;

public:
	void calculateTax();
};

#endif
