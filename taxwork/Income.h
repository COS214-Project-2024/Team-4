#ifndef INCOME_H
#define INCOME_H

#include "TaxType.h"

class Income : public TaxType {
private:
    double incomeTax; 

public:
    Income(double rate);
    double calculateTax(double val) override; 
    void setTax(double rate) override;
};

#endif // INCOME_H
