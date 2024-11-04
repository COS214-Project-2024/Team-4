// IncomeTax.h

#ifndef INCOME_H
#define INCOME_H

#include "TaxType.h"

class Income : public TaxType {
public:
    Income(double rate);
    virtual ~Income() override;

    virtual double calculateTax(double income) override;
    double getMonthlyIncome();
    double calculateMonthlyIncome(double income);
private:
    double rate;
    double income;
};

#endif // INCOME_H
