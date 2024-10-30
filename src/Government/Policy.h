#ifndef POLICY_H
#define POLICY_H

#include <string>

class Policy {

private:
    std::string policyName;
    std::string impactLevel;

public:
    void implement();
    void revoke();
};

#endif