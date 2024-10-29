#ifndef RESIDENTIALBUILDINGBUILDER_H
#define RESIDENTIALBUILDINGBUILDER_H
#include "Builder.h"
#include "ResidentialBuilding.h"
#include<string>
using namespace std;

class ResidentialBuildingBuilder :public Builder {

private:
	int residentialUnit;
	float comfort;

public:
	void setResidentialUnit(int unit);

	void setComfort(float comfort);

	int getResidentialUnit();

	float getComfort();

public:
	ResidentialBuildingBuilder();

	ResidentialBuilding build();
};

#endif
