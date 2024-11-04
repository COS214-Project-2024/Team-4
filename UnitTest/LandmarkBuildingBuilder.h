#ifndef LANDMARKBUILDINGBUILDER_H
#define LANDMARKBUILDINGBUILDER_H
#include "Builder.h"
#include "LandmarkBuilding.h"
#include<string>
#include <memory>
using namespace std;

class LandmarkBuildingBuilder : public Builder {

private:
	 int visitorCapacity = 0;
    float culturalValue = 0.0f;
    bool isHistoric = false;

public:
	int getVisitorCapacity();

	//void setVisitorCapacity(int visitorCapacity);

	float getCulturalValue();

	//void setCulturalValue(float culturalValue);

	bool getIsHistoric();

	//void setIsHistoric(bool isHistoric);

    LandmarkBuildingBuilder& setVisitorCapacity(int visitorCapacity);
    LandmarkBuildingBuilder& setCulturalValue(float culturalValue);
    LandmarkBuildingBuilder& setIsHistoric(bool isHistoric);

	LandmarkBuildingBuilder();
	std::unique_ptr<Building> build() override;

};

#endif
