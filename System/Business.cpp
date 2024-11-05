#include "Business.h"
#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;

// Constructor for Business
// Initializes the business with initial revenue and tax rate
Business::Business(double initialRevenue, double initialTaxRate, std::string name)
    : revenue(initialRevenue), taxRate(initialTaxRate), taxCooldownPeriod(std::chrono::seconds(5)), name(name) {}

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

double Business::payTaxes(TaxType* taxType) {
    char taxTypeChar = taxType->getTaxType();
    auto now = std::chrono::steady_clock::now();

    // Check if the business is on cooldown for this tax type
    auto it = lastTaxPayments.find(taxTypeChar);
    if (it != lastTaxPayments.end()) {
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - it->second);
        if (elapsed < taxCooldownPeriod) {
            cout << "Business is on cooldown for tax type " << taxTypeChar << ". Taxes cannot be collected now.\n";
            return 0.0;
        }
    }

    double tax = taxType->calculateTax(revenue);
    if (tax > 0.0) {
        revenue -= tax;
        lastTaxPayments[taxTypeChar] = now; // Update last payment time for this tax type
        cout << "Business paid R" << tax << " in taxes for tax type " << taxTypeChar << ". Remaining revenue: " << revenue << endl;
        return tax;
    } else {
        cout << "Business has insufficient revenue to pay taxes.\n";
        return 0.0;
    }
}

void Business::setTaxCooldownPeriod(int seconds) {
    taxCooldownPeriod = std::chrono::seconds(seconds);
}

double Business::getRevenue() {
    return revenue;
}
double Business::getTaxRate() {
    return taxRate;
}
std::string Business::getName() {
    return name;
}