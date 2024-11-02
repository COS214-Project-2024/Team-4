
#ifndef POLICY_H
#define POLICY_H

#include <string>

class Policy {

private:
    std::string policyName;   // Name of the policy
    std::string impactLevel;  // Impact level of the policy

public:
    // Implements the policy
    void implement();

    // Revokes the policy
    void revoke();
};

