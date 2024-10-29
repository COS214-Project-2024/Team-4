#ifndef DIRECTOR_H
#define DIRECTOR_H

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
