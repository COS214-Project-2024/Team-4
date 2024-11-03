#ifndef POLICY_H
#define POLICY_H

#include <string>
#include "ResourceType.h"

class Policy {

private:
    std::string policyName;   // Name of the policy
    std::string impactLevel;  // Impact level of the policy
    ResourceType type;        // type
    int limit;                // resource limit in policy 

public:
    //Constructor
    Policy(ResourceType type, int limit) : type(type), limit(limit) {}

    // Implements the policy
    void implement();

    // Revokes the policy
    void revoke();
};

#endif