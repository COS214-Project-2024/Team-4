#ifndef POPULATIONMANAGER_H
#define POPULATIONMANAGER_H

#include "Citizen.h"
#include "Observer.h"
#include <list>
class PopulationManager {

private:
	list<Citizen*> citizens;
	int birthRate;
	int migrationRate;
	int deathRate;

public:
	PopulationManager(int birthRate, int migrationRate, int deathRate);

	void simulatePopulationGrowth();

	void addCitizen(Citizen* citizen);

	int getPopulation();

	void addObserver(Observer* observer);

	void notifyObservers();
};

#endif
