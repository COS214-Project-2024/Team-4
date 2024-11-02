#ifndef POLICY_H
#define POLICY_H
//policy
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
