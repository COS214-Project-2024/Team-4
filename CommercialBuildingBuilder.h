#ifndef COMMERCIALBUILDINGBUILDER_H
#define COMMERCIALBUILDINGBUILDER_H
#include "Builder.h"
#include "CommercialBuilding.h"
#include<string>
using namespace std;

class CommercialBuildingBuilder :public Builder {

private:
	int businessUnits;
	float customerTraffic;

public:
	void setBusinessUnits(int units);

	int getBusinessUnits();

	float getCustomerTraffic();

	void setCustomerTraffic(float customerTraffic);

	CommercialBuildingBuilder();

	CommercialBuilding build();
};

#endif
