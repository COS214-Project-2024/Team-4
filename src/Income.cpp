#include "Income.h"
// Initialize with base salary and set bonus and deductions to zero
Income::Income(double salary)
    : baseSalary(salary), bonus(0.0), deductions(0.0) {}

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
void Income::calculateTax() {
	// TODO - implement Income::calculateTax
	throw "Not yet implemented";
}

void Income::setTax(double taxRate) {
	
}
