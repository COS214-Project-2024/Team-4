#ifndef UTILITYMEDIATOR_H
#define UTILITYMEDIATOR_H

#include "ResourceType.h"
#include "Resource.h"
//! might need to add all the other resources of that design pattern

class UtilityMediator {


public:
	bool requestResources(ResourceType type, int amount);

	void releaseResources(ResourceType type, int amount);

	void produceResource(ResourceType type, int amount);
};

#endif
