#ifndef VAT_H
#define VAT_H
#include "TaxType.h"
class VAT : public TaxType {

private:
	double vat;
	char cType;

public:
	void setTax(double rate);

	void calculateTax();
};

#endif
