#ifndef RESIDENTIALBUILDINGBUILDER_H
#define RESIDENTIALBUILDINGBUILDER_H
#include "Builder.h"
#include "ResidentialBuilding.h"
#include<string>
#include<memory>
using namespace std;

class ResidentialBuildingBuilder :public Builder {

private:
	int residentialUnit = 0;
	float comfort = 0.0f;

public:
	ResidentialBuildingBuilder& setResidentialUnit(int unit);
    ResidentialBuildingBuilder& setComfort(float comfort);
	ResidentialBuildingBuilder();
	int getResidentialUnit();

	float getComfort();


	std::unique_ptr<Building> build() override;
};

#endif
