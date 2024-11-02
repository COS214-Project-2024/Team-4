// IncomeTax.h

#ifndef INCOME_H
#define INCOME_H

#include "TaxType.h"

class Income : public TaxType {
public:
    Income(double rate);
    virtual ~Income() override;

    virtual double calculateTax(double income) override;

private:
    double rate;
};

#endif // INCOME_H
