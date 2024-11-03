#include "Policy.h"
#include <iostream>

using namespace std;

// Default constructor
Policy::Policy() : policyName(""), impactLevel("") {}

// Constructor with parameters
Policy::Policy(const std::string& name, const std::string& impact)
    : policyName(name), impactLevel(impact) {}

// Implements the policy
// Prints a message indicating the policy implementation with its impact level
void Policy::implement() {
    cout << "Implementing policy: " << policyName << " with impact level: " << impactLevel << endl;
}

// Revokes the policy
// Prints a message indicating the policy revocation with its impact level
void Policy::revoke() {
    cout << "Revoking policy: " << policyName << " with impact level: " << impactLevel << endl;
}

// Gets the name of the policy
std::string Policy::getPolicyName() const {
    return policyName;
}

// Gets the impact level of the policy
std::string Policy::getImpactLevel() const {
    return impactLevel;
}