#ifndef TAXTYPE_H
#define TAXTYPE_H

class TaxType {

private:
	double taxRate;
	char cType;

public:
	void calculateTax();

	void setTax(double rate);
};

#endif
