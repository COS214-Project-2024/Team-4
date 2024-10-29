#ifndef LANDMARKBUILDINGBUILDER_H
#define LANDMARKBUILDINGBUILDER_H

class LandmarkBuildingBuilder : Builder {

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

	LandMarkBuilding build();
};

#endif
