#include "Policy.h"
#include <iostream>

using namespace std;

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