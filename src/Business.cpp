#include "Business.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Constructor for Business
// Initializes the business with initial revenue and tax rate
Business::Business(double initialRevenue, double initialTaxRate)
    : revenue(initialRevenue), taxRate(initialTaxRate) {}

// Updates the tax rate for the business
// Prints the updated tax rate to the console
void Business::updateTaxRate(double rate) {
    taxRate = rate;
    cout << "Business tax rate updated to " << taxRate << "%" << endl;
}

// Updates the business policy
// Prints a message indicating the policy update
void Business::updatePolicy(Policy policy) {
    policies.push_back(policy);
    cout << "Business policy updated." << endl;
}

// Updates the services provided by the business
// Prints a message indicating the services update
void Business::updateServices(CityService service) {
    services.push_back(service.getServiceName());
    cout << "Business services updated." << endl;
}

// Processes the payment of tax by the business
// Deducts the tax amount from the revenue and prints the remaining revenue
void Business::payTax(double amount) {
    revenue -= amount;
    cout << "Business paid tax: " << amount << ". Remaining revenue: " << revenue << endl;
}

// Adds a new service to the business
void Business::addService(const std::string& serviceName) {
    services.push_back(serviceName);
    cout << "Added service: " << serviceName << endl;
}

// Removes a service from the business
void Business::removeService(const std::string& serviceName) {
    auto it = find(services.begin(), services.end(), serviceName);
    if (it != services.end()) {
        services.erase(it);
        cout << "Removed service: " << serviceName << endl;
    } else {
        cout << "Service not found: " << serviceName << endl;
    }
}

// Adds a new policy to the business
void Business::addPolicy(const Policy& policy) {
    policies.push_back(policy);
    cout << "Added policy: " << policy.getPolicyName() << endl;
}

// Removes a policy from the business
void Business::removePolicy(const Policy& policy) {
    auto it = find_if(policies.begin(), policies.end(), [&policy](const Policy& p) {
        return p.getPolicyName() == policy.getPolicyName();
    });
    if (it != policies.end()) {
        policies.erase(it);
        cout << "Removed policy: " << policy.getPolicyName() << endl;
    } else {
        cout << "Policy not found: " << policy.getPolicyName() << endl;
    }
}

// Calculates the total tax to be paid based on the current tax rate and revenue
double Business::calculateTax() const {
    return revenue * taxRate / 100;
}

// Prints the details of the business
void Business::printDetails() const {
    cout << "Business Details:" << endl;
    cout << "Revenue: " << revenue << endl;
    cout << "Tax Rate: " << taxRate << "%" << endl;
    cout << "Services: ";
    for (const auto& service : services) {
        cout << service << " ";
    }
    cout << endl;
    cout << "Policies: ";
    for (const auto& policy : policies) {
        cout << policy.getPolicyName() << " ";
    }
    cout << endl;
}