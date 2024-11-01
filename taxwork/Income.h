#ifndef INCOME_H
#define INCOME_H

#include "TaxType.h"

class Income : public TaxType {

private:
	double incomeTax;
	char cType;

public:
	Income(double rate, char type);
	void setTax(double rate);
	double calculateTax(double val) override;
};

#endif
