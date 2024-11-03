// BudgetApprovalHandler.h
#ifndef BUDGETAPPROVALHANDLER_H
#define BUDGETAPPROVALHANDLER_H

#include "ResourceApprovalHandler.h"
#include "Government.h"

class BudgetApprovalHandler : public ResourceApprovalHandler {
private:
    Government* government;
    int resourceCost;

public:
    BudgetApprovalHandler(Government* gov, int cost) : government(gov), resourceCost(cost) {}

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
