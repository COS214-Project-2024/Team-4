#ifndef PROPERTY_H
#define PROPERTY_H

#include "TaxType.h"

class Property : public TaxType {
private:
    double propertyTax;   // Base property tax rate as a percentage
    double municipalLevy; // Additional municipal levy as a percentage
    double additionalFees; // Fixed additional fees

public:
    Property(double rate, double levy, double fees);
    void setTax(double rate) override;
    double calculateTax(double propertyValue) override;
    void setMunicipalLevy(double levy);
    void setAdditionalFees(double fees);
};

#endif // PROPERTY_H
