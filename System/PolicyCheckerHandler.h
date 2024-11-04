// PolicyCheckHandler.h
#ifndef POLICYCHECKHANDLER_H
#define POLICYCHECKHANDLER_H

#include "ResourceApprovalHandler.h"
#include "Government.h"
#include "Policy.h"

class PolicyCheckHandler : public ResourceApprovalHandler {
private:
    Government* government;
    bool policyEnforced; // Internal state to track if the policy was enforced

public:
    PolicyCheckHandler(Government* gov) : government(gov), policyEnforced(false) {}

    bool handleRequest(ResourceType type, int quantity) override {
        Policy policy(type, quantity);
        government->enforcePolicy(policy);
        if (isPolicyEnforced()) {
            return ResourceApprovalHandler::handleRequest(type, quantity);
        }
        return false;
    }

    // Method to determine if a policy was enforced
    bool isPolicyEnforced() const {
        return policyEnforced;
    }

    void setPolicyEnforced(bool enforced) {
        policyEnforced = enforced;
    }
};

#endif // POLICYCHECKHANDLER_H
