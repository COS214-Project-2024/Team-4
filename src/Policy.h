#ifndef POLICY_H
#define POLICY_H

#include <string>

class Policy {

private:
    std::string policyName;   // Name of the policy
    std::string impactLevel;  // Impact level of the policy

public:
    // Default constructor
    Policy();

    // Constructor with parameters
    Policy(const std::string& name, const std::string& impact);

    // Implements the policy
    void implement();

    // Revokes the policy
    void revoke();

    // Gets the name of the policy
    std::string getPolicyName() const;

    // Gets the impact level of the policy
    std::string getImpactLevel() const;
};

#endif