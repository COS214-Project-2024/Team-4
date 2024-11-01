// PopulationManager.h

#ifndef POPULATIONMANAGER_H
#define POPULATIONMANAGER_H

#include "CitizenObserver.h"
#include <vector>
#include <memory>

class Citizen;

class PopulationManager : public CitizenObserver {
private:
    std::vector<std::shared_ptr<Citizen>> citizens;

public:
    void addCitizen(std::shared_ptr<Citizen> citizen);
    void update(Citizen* citizen) override;  // Override the update method to respond to Citizen changes

    // Additional methods to handle population growth, if needed
};

#endif // POPULATIONMANAGER_H


