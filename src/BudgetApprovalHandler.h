/**
 * @file BudgetApprovalHandler.h
 * @brief Definition of the BudgetApprovalHandler class.
 * 
 * This file contains the definition of the BudgetApprovalHandler class, which is responsible
 * for handling budget approval requests. It includes methods to handle requests and allocate
 * budget to city services.
 * 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @note This file is part of a project for managing city budgets and services.
 */

#ifndef BUDGETAPPROVALHANDLER_H
#define BUDGETAPPROVALHANDLER_H

#include "ResourceApprovalHandler.h"
#include "Government.h"

/**
 * @class BudgetApprovalHandler
 * @brief Handles budget approval requests.
 * 
 * This class is responsible for handling budget approval requests. It includes methods to handle
 * requests and allocate budget to city services.
 */
class BudgetApprovalHandler : public ResourceApprovalHandler {
private:
    Government* government; ///< Pointer to the government object
    int resourceCost;       ///< Cost of the resource

public:
    /**
     * @brief Construct a new Budget Approval Handler object.
     * 
     * @param gov Pointer to the government object.
     * @param cost Cost of the resource.
     */
    BudgetApprovalHandler(Government* gov, int cost) : government(gov), resourceCost(cost) {}

    /**
     * @brief Handles the budget approval request.
     * 
     * Calculates the total cost and allocates the budget if sufficient funds are available.
     * 
     * @param type The type of resource.
     * @param quantity The quantity of the resource.
     * @return true if the request is approved and budget is allocated.
     * @return false if the request is denied due to insufficient budget.
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