#ifndef INCOME_H
#define INCOME_H

#include "TaxType.h"

class Income : TaxType {

private:
	double incomeTax;
	char cType;
	double baseSalary;      // Base salary for the job
    double bonus;           // Monthly bonus (if any)
    double deductions;      // Monthly deductions (if any)

public:
// Constructor to initialize with base salary
    Income(double salary);

    // Method to calculate monthly income
    double calculateMonthlyIncome() const;

    // Optional methods to adjust income
    void addBonus(double amount);
    void applyDeductions(double amount);

    // Getters
    double getBaseSalary() const { return baseSalary; }
    double getBonus() const { return bonus; }
    double getDeductions() const { return deductions; }
	void calculateTax() override;

	void setTax(double rate) override;
};

#endif
