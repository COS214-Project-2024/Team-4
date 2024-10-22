#ifndef TAXTYPE_H
#define TAXTYPE_H

class TaxType {
protected:
    double taxRate;
    char cType; //tax type identifier
public:
    virtual void calculateTax() = 0; 
    virtual void setTax(double rate) = 0;
};

#endif
