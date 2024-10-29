#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "Builder.h"
#include<string>
using namespace std;	

class Director {

private:
	Builder builder;

public:
	void setBuilder(Builder builder);

	void constructSmallBuilding();

	void constructMediumBuilding();

	void constructLargeBuilding();
};

#endif
