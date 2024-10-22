#ifndef RESIDENTIALBUILDINGBUILDER_H
#define RESIDENTIALBUILDINGBUILDER_H

class ResidentialBuildingBuilder : Builder {

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
