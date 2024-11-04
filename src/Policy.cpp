/**
 * @file Policy.cpp
 * @brief Implementation of the Policy class.
 * @version 1.0
 * 
 * This file contains the implementation of the Policy class, which represents a policy
 * with specific attributes and behaviors.
 */

#include "Policy.h"
#include <iostream>

using namespace std;

/**
 * @brief Default constructor for Policy.
 */
Policy::Policy() : policyName(""), impactLevel("") {}

/**
 * @brief Constructor for Policy with parameters.
 * @param name The name of the policy.
 * @param impact The impact level of the policy.
 */
Policy::Policy(const std::string& name, const std::string& impact)
    : policyName(name), impactLevel(impact) {}

/**
 * @brief Implements the policy.
 * 
 * Prints a message indicating the policy implementation with its impact level.
 */
void Policy::implement() {
    cout << "Implementing policy: " << policyName << " with impact level: " << impactLevel << endl;
}

/**
 * @brief Revokes the policy.
 * 
 * Prints a message indicating the policy revocation with its impact level.
 */
void Policy::revoke() {
    cout << "Revoking policy: " << policyName << " with impact level: " << impactLevel << endl;
}

/**
 * @brief Gets the name of the policy.
 * @return The name of the policy.
 */
std::string Policy::getPolicyName() const {
    return policyName;
}

/**
 * @brief Gets the impact level of the policy.
 * @return The impact level of the policy.
 */
std::string Policy::getImpactLevel() const {
    return impactLevel;
}