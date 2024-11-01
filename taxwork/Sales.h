#ifndef SALES_H
#define SALES_H

#include "TaxType.h"

class Sales : public TaxType {

private:
	double SalesTax;
	char cType;

public:
	Sales(double rate, char type);
	void setTax(double rate);
	double calculateTax(double val) override;
};

#endif
