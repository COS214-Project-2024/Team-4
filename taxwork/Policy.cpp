#include "Policy.h"
#include <iostream>

using namespace std;

void Policy::setPolicyName(string name) {
    policyName = name;
}

string Policy::getPolicyName() const {
    return policyName;
}

void Policy::implement() {
    cout << "Implementing policy: " << policyName << " with impact level: " << impactLevel << endl;
}

void Policy::revoke() {
    cout << "Revoking policy: " << policyName << " with impact level: " << impactLevel << endl;
}