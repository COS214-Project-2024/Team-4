#include "Business.h"
#include <iostream>

using namespace std;

void Business::updateTaxRate(double rate) {
    taxRate = rate;
    cout << "Business tax rate updated to " << taxRate << "%" << endl;
}

void Business::updatePolicy(Policy policy) {
    cout << "Business policy updated." << endl;
}

void Business::updateServices(CityService service) {
    cout << "Business services updated." << endl;
}

void Business::payTax(double amount) {
    revenue -= amount;
    cout << "Business paid tax: " << amount << ". Remaining revenue: " << revenue << endl;
}