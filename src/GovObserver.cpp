/**
 * @file GovObserver.cpp
 * @brief Implementation of the GovObserver class.
 * @version 1.0
 * 
 * This file contains the implementation of the GovObserver class, which provides methods to update
 * the tax rate, policy, and services for the observer.
 */

#include "GovObserver.h"
#include "Policy.h"
#include "CityService.h"
#include <iostream>

using namespace std;

/**
 * @brief Updates the tax rate for the observer.
 * @param rate The new tax rate.
 * 
 * Prints the updated tax rate to the console.
 */
void GovObserver::updateTaxRate(double rate) {
    cout << "Tax rate updated to " << rate << "%" << endl;
}

/**
 * @brief Updates the policy for the observer.
 * @param policy The new policy.
 * 
 * Prints a message indicating the policy update.
 */
void GovObserver::updatePolicy(Policy policy) {
    cout << "Policy updated." << endl;
}

/**
 * @brief Updates the services for the observer.
 * @param services The new services.
 * 
 * Prints a message indicating the services update.
 */
void GovObserver::updateServices(CityService services) {
    cout << "Services updated." << endl;
}