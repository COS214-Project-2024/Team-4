/**
 * @file PolicyCheckerHandler.h
 * @brief Definition of the PolicyCheckerHandler class.
 * @version 1.0
 * 
 * This file contains the definition of the PolicyCheckerHandler class, which handles
 * policy enforcement checks for resource approval requests.
 */

#ifndef POLICYCHECKHANDLER_H
#define POLICYCHECKHANDLER_H

#include "ResourceApprovalHandler.h"
#include "Government.h"
#include "Policy.h"

/**
 * @class PolicyCheckerHandler
 * @brief Handles policy enforcement checks for resource approval requests.
 * 
 * The PolicyCheckerHandler class inherits from ResourceApprovalHandler and provides
 * methods to enforce policies and handle resource approval requests based on policy enforcement.
 */
class PolicyCheckerHandler : public ResourceApprovalHandler {
private:
    Government* government; ///< Pointer to the Government object.
    bool policyEnforced; ///< Internal state to track if the policy was enforced.

public:
    /**
     * @brief Constructor for PolicyCheckerHandler.
     * @param gov Pointer to the Government object.
     */
    PolicyCheckerHandler(Government* gov) : government(gov), policyEnforced(false) {}

    /**
     * @brief Handles the resource approval request.
     * @param type The type of the resource.
     * @param quantity The quantity of the resource.
     * @return True if the request is approved, false otherwise.
     */
    bool handleRequest(ResourceType type, int quantity) override {
        Policy policy(type, quantity);
        government->enforcePolicy(policy);
        if (isPolicyEnforced()) {
            return ResourceApprovalHandler::handleRequest(type, quantity);
        }
        return false;
    }

    /**
     * @brief Determines if a policy was enforced.
     * @return True if the policy was enforced, false otherwise.
     */
    bool isPolicyEnforced() const {
        return policyEnforced;
    }

    /**
     * @brief Sets the policy enforcement state.
     * @param enforced True if the policy was enforced, false otherwise.
     */
    void setPolicyEnforced(bool enforced) {
        policyEnforced = enforced;
    }
};

#endif // POLICYCHECKHANDLER_H