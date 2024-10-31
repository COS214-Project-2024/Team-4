#ifndef SEWAGEMANAGMENT_H
#define SEWAGEMANAGMENT_H

#include "Utility.h"

class SewageManagment : Utility {

public:
	Utility mediator;

	void manageSewage(Building *building);

	SewageManagment();
};

#endif
