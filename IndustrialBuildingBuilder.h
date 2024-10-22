#ifndef INDUSTRIALBUILDINGBUILDER_H
#define INDUSTRIALBUILDINGBUILDER_H

class IndustrialBuildingBuilder : Builder {

private:
	float pollutionLevel;
	float productionCapacity;

public:
	void setPollutionLevel(float pollutionLevel);

	void setProductionCapacity(float productionCapacity);

	float getPollutionLevel();

	float getProductionCapacity();

	IndustrialBuildingBuilder();

	IndustrialBuilding build();
};

#endif
