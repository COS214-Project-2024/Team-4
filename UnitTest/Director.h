#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "Builder.h"
#include<string>
using namespace std;	

class Director {

private:
	Builder* builder;

public:
	void setBuilder(Builder& builder);

	std::unique_ptr<Building> constructSmallBuilding();

    std::unique_ptr<Building> constructMediumBuilding();
	
    std::unique_ptr<Building> constructLargeBuilding();
};

#endif
