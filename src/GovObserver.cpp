#include "GovObserver.h"
#include "Policy.h"
#include "CityService.h"
#include <iostream>
//GOV
using namespace std;

void GovObserver::updateTaxRate(double rate) {
    cout << "Tax rate updated to " << rate << "%" << endl;
}

void GovObserver::updatePolicy(Policy policy) {
    cout << "Policy updated." << endl;
}

void GovObserver::updateServices(CityService services) {
    cout << "Services updated." << endl;
}
