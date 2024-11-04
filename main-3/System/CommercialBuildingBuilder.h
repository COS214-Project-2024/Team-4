#ifndef COMMERCIALBUILDINGBUILDER_H
#define COMMERCIALBUILDINGBUILDER_H
#include "Builder.h"
#include "CommercialBuilding.h"
#include <string>
#include <memory>
using namespace std;

class CommercialBuildingBuilder :public Builder {

private:
	int businessUnits = 0;
	float customerTraffic = 0.0f;

public:
 	CommercialBuildingBuilder& setBusinessUnits(int units);

	int getBusinessUnits();

	float getCustomerTraffic();

	CommercialBuildingBuilder& setCustomerTraffic(float customerTraffic);

	CommercialBuildingBuilder();

	std::unique_ptr<Building> build() override;
};

#endif
