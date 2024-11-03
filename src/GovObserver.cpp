#include "GovObserver.h"
#include "Policy.h"
#include "CityService.h"
#include <iostream>

using namespace std;

// Updates the tax rate for the observer
// Prints the updated tax rate to the console
void GovObserver::updateTaxRate(double rate) {
    cout << "Tax rate updated to " << rate << "%" << endl;
}

// Updates the policy for the observer
// Prints a message indicating the policy update
void GovObserver::updatePolicy(Policy policy) {
    cout << "Policy updated." << endl;
}

// Updates the services for the observer
// Prints a message indicating the services update
void GovObserver::updateServices(CityService services) {
    cout << "Services updated." << endl;
}