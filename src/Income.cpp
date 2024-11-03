#include "Income.h"
// Initialize with base salary and set bonus and deductions to zero

// Calculate monthly income considering base salary, bonuses, and deductions
double Income::calculateMonthlyIncome() const {
    return baseSalary + bonus - deductions;
}

// Add a bonus to the income for the current month
void Income::addBonus(double amount) {
    bonus += amount;
}

// Apply deductions for the current month
void Income::applyDeductions(double amount) {
    deductions += amount;
	deductions += incomeTax;
}

void Income::setTax(double taxRate) {
	
}
