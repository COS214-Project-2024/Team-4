#ifndef VAT_H
#define VAT_H
#include "TaxType.h"
class VAT : public TaxType {

private:
	double vat;

public:
	VAT(double rate);
	void setTax(double rate);
	double calculateTax(double val) override;
};

#endif
