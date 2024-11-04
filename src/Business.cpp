/**
 * @file Business.cpp
 * @brief Implementation of the Business class.
 * 
 * This file contains the implementation of the Business class, which manages business operations
 * such as updating tax rates, policies, and services, processing tax payments, and printing business details.
 * 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @note This file is part of a project for managing city businesses and their properties.
 */

#include "Business.h"
#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;

/**
 * @brief Constructs a new Business object.
 * 
 * @param initialRevenue The initial revenue of the business.
 * @param initialTaxRate The initial tax rate for the business.
 */
Business::Business(double initialRevenue, double initialTaxRate)
    : revenue(initialRevenue), taxRate(initialTaxRate), taxCooldownPeriod(std::chrono::seconds(5)) {}

/**
 * @brief Updates the tax rate for the business.
 * 
 * @param rate The new tax rate.
 */
void Business::updateTaxRate(double rate) {
    taxRate = rate;
    cout << "Business tax rate updated to " << taxRate << "%" << endl;
}

/**
 * @brief Updates the business policy.
 * 
 * @param policy The new policy to be added.
 */
void Business::updatePolicy(Policy policy) {
    policies.push_back(policy);
    cout << "Business policy updated." << endl;
}

/**
 * @brief Updates the services provided by the business.
 * 
 * @param service The new service to be added.
 */
void Business::updateServices(CityService service) {
    services.push_back(service.getServiceName());
    cout << "Business services updated." << endl;
}

/**
 * @brief Processes the payment of tax by the business.
 * 
 * @param amount The amount of tax to be paid.
 */
void Business::payTax(double amount) {
    revenue -= amount;
    cout << "Business paid tax: " << amount << ". Remaining revenue: " << revenue << endl;
}

/**
 * @brief Adds a new service to the business.
 * 
 * @param serviceName The name of the service to be added.
 */
void Business::addService(const std::string& serviceName) {
    services.push_back(serviceName);
    cout << "Added service: " << serviceName << endl;
}

/**
 * @brief Removes a service from the business.
 * 
 * @param serviceName The name of the service to be removed.
 */
void Business::removeService(const std::string& serviceName) {
    auto it = find(services.begin(), services.end(), serviceName);
    if (it != services.end()) {
        services.erase(it);
        cout << "Removed service: " << serviceName << endl;
    } else {
        cout << "Service not found: " << serviceName << endl;
    }
}

/**
 * @brief Adds a new policy to the business.
 * 
 * @param policy The policy to be added.
 */
void Business::addPolicy(const Policy& policy) {
    policies.push_back(policy);
    cout << "Added policy: " << policy.getPolicyName() << endl;
}

/**
 * @brief Removes a policy from the business.
 * 
 * @param policy The policy to be removed.
 */
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

/**
 * @brief Calculates the total tax to be paid based on the current tax rate and revenue.
 * 
 * @return double The total tax to be paid.
 */
double Business::calculateTax() const {
    return revenue * taxRate / 100;
}

/**
 * @brief Prints the details of the business.
 */
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

/**
 * @brief Processes the payment of taxes by the business based on the tax type.
 * 
 * @param taxType Pointer to the tax type.
 * @return double The amount of taxes paid.
 */
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
        cout << "Business paid $" << tax << " in taxes for tax type " << taxTypeChar << ". Remaining revenue: " << revenue << endl;
        return tax;
    } else {
        cout << "Business has insufficient revenue to pay taxes.\n";
        return 0.0;
    }
}