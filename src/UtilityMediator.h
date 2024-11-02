// UtilityMediator.h
#ifndef UTILITYMEDIATOR_H
#define UTILITYMEDIATOR_H

#include "ResourceType.h"
#include "Observer.h"
#include <map>

class UtilityMediator : public Observer {
private:
    std::map<ResourceType, int> resourceInventory;

public:

    UtilityMediator() = default;
    bool requestResources(ResourceType type, int amount);
    void releaseResources(ResourceType type, int amount);
    void produceResource(ResourceType type, int amount);
    int getAvailableResource(ResourceType type) const;
    void update(ResourceType type, int quantity) override;
};

#endif // UTILITYMEDIATOR_H
