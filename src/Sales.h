#ifndef SALES_H
#define SALES_H

#include "TaxType.h"

class Sales : TaxType {

private:
	double SalesTax;
	char cType;

public:
	void setTax(double rate);

	void calculateTax();
};

#endif
