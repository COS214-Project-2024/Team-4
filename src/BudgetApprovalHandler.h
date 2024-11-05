/**
 * @file BudgetApprovalHandler.h
 * @brief Declaration of the BudgetApprovalHandler class.
 * 
 * This file contains the declaration of the BudgetApprovalHandler class, which handles
 * budget approval requests for resource allocation.
 *
 * @version 1.0
 * @date 04/10/2024
 * 
 * @see BudgetApprovalHandler.cpp
 */

#ifndef BUDGETAPPROVALHANDLER_H
#define BUDGETAPPROVALHANDLER_H

#include "ResourceApprovalHandler.h"
#include "Government.h"

/**
 * @class BudgetApprovalHandler
 * @brief Handles budget approval requests for resource allocation.
 * 
 * The BudgetApprovalHandler class handles budget approval requests for resource allocation.
 * It checks if the government has enough budget to allocate for the requested resources.
 * 
 * @version 1.0
 * @date 04/10/2024
 */
class BudgetApprovalHandler : public ResourceApprovalHandler {
private:
    Government* government; ///< Pointer to the government object
    int resourceCost;       ///< Cost of the resource

public:
    /**
     * @brief Constructor for BudgetApprovalHandler.
     * 
     * Initializes the handler with the government and resource cost.
     * 
     * @param gov Pointer to the Government object.
     * @param cost The cost of the resource.
     */
    BudgetApprovalHandler(Government* gov, int cost) : government(gov), resourceCost(cost) {}

    /**
     * @brief Handles the resource approval request.
     * 
     * Checks if the government has enough budget to allocate for the requested resources.
     * 
     * @param type The type of resource.
     * @param quantity The quantity of the resource.
     * @return True if the request is approved, false otherwise.
     */
    bool handleRequest(ResourceType type, int quantity) override {
        double totalCost = resourceCost * quantity;
        CityService service("Resource Allocation", totalCost); // Placeholder CityService instance

        if (government->getBudget() >= totalCost) {
            government->allocateBudget(service, totalCost);
            return ResourceApprovalHandler::handleRequest(type, quantity);
        }
        return false;
    }
};

#endif // BUDGETAPPROVALHANDLER_H