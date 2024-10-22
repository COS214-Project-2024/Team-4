#ifndef COMMERCIALBUILDINGBUILDER_H
#define COMMERCIALBUILDINGBUILDER_H

class CommercialBuildingBuilder : Builder {

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
