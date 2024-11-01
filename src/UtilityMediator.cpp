#include "UtilityMediator.h"

bool UtilityMediator::requestResources(ResourceType type, int amount) {
	 if (resourceInventory[type] >= amount) {
            resourceInventory[type] -= amount;
            return true;  // Request fulfilled
        }
        return false;  // Insufficient resources
}

void UtilityMediator::releaseResources(ResourceType type, int amount) {
	resourceInventory[type] += amount;
}

void UtilityMediator::produceResource(ResourceType type, int amount) {
	resourceInventory[type] += amount;
}

int UtilityMediator::getAvailableResource(ResourceType type) const
{
	return resourceInventory.count(type) ? resourceInventory.at(type) : 0;
}
//! Compare this snippet from src/ResourceType.h:


