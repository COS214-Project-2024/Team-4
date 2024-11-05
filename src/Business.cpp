/**
 * @file Business.cpp
 * @brief Implementation of the Business class.
 * 
 * This file contains the implementation of the Business class, which represents a business
 * and includes methods to manage its revenue, tax rate, policies, and services.
 *
 * @version 1.0
 * @date 04/10/2024
 * 
 * @see Business.h
 */

#include "Business.h"
#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;

/**
 * @brief Constructor for Business.
 * 
 * Initializes the business with initial revenue and tax rate.
 * 
 * @param initialRevenue The initial revenue of the business.
 * @param initialTaxRate The initial tax rate of the business.
 */
Business::Business(double initialRevenue, double initialTaxRate)
    : revenue(initialRevenue), taxRate(initialTaxRate), taxCooldownPeriod(std::chrono::seconds(5)) {}

/**
 * @brief Updates the tax rate for the business.
 * @param rate The new tax rate.
 */
void Business::updateTaxRate(double rate) {
    taxRate = rate;
    cout << "Business tax rate updated to " << taxRate << "%" << endl;
}

/**
 * @brief Updates the business policy.
 * @param policy The new policy to be added.
 */
void Business::updatePolicy(Policy policy) {
    policies.push_back(policy);
    cout << "Business policy updated." << endl;
}

/**
 * @brief Updates the services provided by the business.
 * @param service The new service to be added.
 */
void Business::updateServices(CityService service) {
    services.push_back(service.getServiceName());
    cout << "Business services updated." << endl;
}

/**
 * @brief Processes the payment of tax by the business.
 * @param amount The amount of tax to be paid.
 */
void Business::payTax(double amount) {
    revenue -= amount;
    cout << "Business paid tax: " << amount << ". Remaining revenue: " << revenue << endl;
}

/**
 * @brief Adds a new service to the business.
 * @param serviceName The name of the service to be added.
 */
void Business::addService(const std::string& serviceName) {
    services.push_back(serviceName);
    cout << "Added service: " << serviceName << endl;
}

/**
 * @brief Removes a service from the business.
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
 * @param policy The policy to be added.
 */
void Business::addPolicy(const Policy& policy) {
    policies.push_back(policy);
    cout << "Added policy: " << policy.getPolicyName() << endl;
}

/**
 * @brief Removes a policy from the business.
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
 * @return The total tax to be paid.
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
 * @brief Processes the payment of taxes by the business.
 * @param taxType Pointer to the TaxType object.
 * @return The amount of tax paid.
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
        cout << "Business paid R" << tax << " in taxes for tax type " << taxTypeChar << ". Remaining revenue: " << revenue << endl;
        return tax;
    } else {
        cout << "Business has insufficient revenue to pay taxes.\n";
        return 0.0;
    }
}

/**
 * @brief Sets the tax cooldown period for the business.
 * @param seconds The cooldown period in seconds.
 */
void Business::setTaxCooldownPeriod(int seconds) {
    taxCooldownPeriod = std::chrono::seconds(seconds);
}

/**
 * @brief Gets the revenue of the business.
 * @return The revenue of the business.
 */
double Business::getRevenue() {
    return revenue;
}

/**
 * @brief Gets the tax rate of the business.
 * @return The tax rate of the business.
 */
double Business::getTaxRate() {
    return taxRate;
}