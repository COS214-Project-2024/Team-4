#ifndef SALES_H
#define SALES_H

#include "TaxType.h"

class Sales : public TaxType {
private:
    double salesTax;          // Base sales tax rate as a percentage
    double environmentalLevy; // Additional environmental levy as a percentage
    double serviceFee;        // Fixed service fee

public:
    // Constructor to initialize sales tax, environmental levy, and service fee
    Sales(double rate, double levy, double fee);

    // Method to set the base sales tax rate
    void setTax(double rate) override;

    // Method to calculate total tax based on sale amount
    double calculateTax(double saleAmount) override;

    // Setters for additional components
    void setEnvironmentalLevy(double levy);
    void setServiceFee(double fee);
};

#endif // SALES_H