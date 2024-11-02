#include "Business.h"
#include <iostream>

using namespace std;

// Updates the tax rate for the business
// Prints the updated tax rate to the console
void Business::updateTaxRate(double rate) {
    taxRate = rate;
    cout << "Business tax rate updated to " << taxRate << "%" << endl;
}

// Updates the business policy
// Prints a message indicating the policy update
void Business::updatePolicy(Policy policy) {
    cout << "Business policy updated." << endl;
}

// Updates the services provided by the business
// Prints a message indicating the services update
void Business::updateServices(CityService service) {
    cout << "Business services updated." << endl;
}

// Processes the payment of tax by the business
// Deducts the tax amount from the revenue and prints the remaining revenue
void Business::payTax(double amount) {
    revenue -= amount;
    cout << "Business paid tax: " << amount << ". Remaining revenue: " << revenue << endl;
}