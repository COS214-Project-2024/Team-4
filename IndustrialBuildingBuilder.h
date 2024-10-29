#ifndef INDUSTRIALBUILDINGBUILDER_H
#define INDUSTRIALBUILDINGBUILDER_H
#include "Builder.h"
#include "IndustrialBuilding.h"
#include<string>
using namespace std;

class IndustrialBuildingBuilder : Builder {

private:
	float pollutionLevel = 0.0f;
	float productionCapacity = 0.0f;

public:
IndustrialBuildingBuilder& setPollutionLevel(float level);
    IndustrialBuildingBuilder& setProductionCapacity(float capacity);

	float getPollutionLevel();

	float getProductionCapacity();

	IndustrialBuildingBuilder();

	std::unique_ptr<Building> build() override;
};

#endif
