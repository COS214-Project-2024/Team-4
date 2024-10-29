#ifndef LANDMARKBUILDINGBUILDER_H
#define LANDMARKBUILDINGBUILDER_H
#include "Builder.h"
#include "LandmarkBuilding.h"
#include<string>
using namespace std;

class LandmarkBuildingBuilder : public Builder {

private:
	int visitorCapacity;
	float culturalValue;
	bool isHistoric;

public:
	int getVisitorCapacity();

	void setVisitorCapacity(int visitorCapacity);

	float getCulturalValue();

	void setCulturalValue(float culturalValue);

	bool getIsHistoric();

	void setIsHistoric(bool isHistoric);

	LandmarkBuilding build();
};

#endif
