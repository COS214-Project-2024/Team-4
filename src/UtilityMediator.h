#ifndef UTILITYMEDIATOR_H
#define UTILITYMEDIATOR_H

#include "ResourceType.h"
//#include "Resource.h"
#include <map>
//! might need to add all the other resources of that design pattern

class UtilityMediator {

	private:
    	std::map<ResourceType, int> resourceInventory;  


	public:
		UtilityMediator();

		bool requestResources(ResourceType type, int amount);

		void releaseResources(ResourceType type, int amount);

		void produceResource(ResourceType type, int amount);

		int getAvailableResource(ResourceType type) const;
};

#endif
