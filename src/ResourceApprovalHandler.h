/**
 * @file ResourceApprovalHandler.h
 * @brief Header file for resource approval handler classes.
 * 
 * This file contains the definition of the ResourceApprovalHandler class and its 
 * derived classes, which provide a chain of responsibility pattern for approving 
 * resource requests.
 * 
 * @version 1.0
 * @date 2024-11-04
 */

#ifndef RESOURCEAPPROVALHANDLER_H
#define RESOURCEAPPROVALHANDLER_H

#include "ResourceType.h"

/**
 * @class ResourceApprovalHandler
 * @brief Base class for handling resource approval requests.
 * 
 * The ResourceApprovalHandler class provides a chain of responsibility pattern 
 * for approving resource requests. Derived classes implement specific approval logic.
 */
class ResourceApprovalHandler {
protected:
    ResourceApprovalHandler* nextHandler; ///< Pointer to the next handler in the chain.

public:
    /**
     * @brief Constructs a new ResourceApprovalHandler object.
     */
    ResourceApprovalHandler() : nextHandler(nullptr) {}

    /**
     * @brief Destroys the ResourceApprovalHandler object.
     */
    virtual ~ResourceApprovalHandler() {}

    /**
     * @brief Sets the next handler in the chain.
     * 
     * @param handler Pointer to the next handler.
     */
    void setNextHandler(ResourceApprovalHandler* handler) {
        nextHandler = handler;
    }

    /**
     * @brief Handles the resource request.
     * 
     * @param type The type of the resource.
     * @param quantity The quantity of the resource.
     * @return True if the request is approved, false otherwise.
     */
    virtual bool handleRequest(ResourceType type, int quantity) {
        if (nextHandler) return nextHandler->handleRequest(type, quantity);
        return false;
    }
};

/**
 * @class BudgetApprovalHandler
 * @brief Handles budget approval requests.
 * 
 * The BudgetApprovalHandler class checks if the budget allows for the requested resource.
 */
class BudgetApprovalHandler : public ResourceApprovalHandler {
public:
    /**
     * @brief Handles the budget approval request.
     * 
     * @param type The type of the resource.
     * @param quantity The quantity of the resource.
     * @return True if the request is approved, false otherwise.
     */
    bool handleRequest(ResourceType type, int quantity) override {
        if (type == ResourceType::Budget) {
            // Check if budget allows for this request
            return ResourceApprovalHandler::handleRequest(type, quantity);
        }
        return false;
    }
};

#endif // RESOURCEAPPROVALHANDLER_H