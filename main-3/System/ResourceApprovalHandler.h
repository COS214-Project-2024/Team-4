// ResourceApprovalHandler.h
#ifndef RESOURCEAPPROVALHANDLER_H
#define RESOURCEAPPROVALHANDLER_H

#include "ResourceType.h"

class ResourceApprovalHandler {
protected:
    ResourceApprovalHandler* nextHandler;

public:
    ResourceApprovalHandler() : nextHandler(nullptr) {}
    virtual ~ResourceApprovalHandler() {}

    void setNextHandler(ResourceApprovalHandler* handler) {
        nextHandler = handler;
    }

    virtual bool handleRequest(ResourceType type, int quantity) {
        if (nextHandler) return nextHandler->handleRequest(type, quantity);
        return false;
    }
};

class BudgetApprovalHandler : public ResourceApprovalHandler {
public:
    bool handleRequest(ResourceType type, int quantity) override {
        if (type == ResourceType::Budget) {
            // Check if budget allows for this request
            return ResourceApprovalHandler::handleRequest(type, quantity);
        }
        return false;
    }
};

#endif // RESOURCEAPPROVALHANDLER_H
