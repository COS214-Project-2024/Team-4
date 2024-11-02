// BuildingManager.h

#ifndef BUILDINGMANAGER_H
#define BUILDINGMANAGER_H

#include <vector>
#include <string>
#include "Building.h"
#include "Citizen.h"

namespace YourNamespace {

class BuildingManager {
public:
    void addBuilding(Building* building);
    void addCitizen(Citizen* citizen);
    bool assignJobToCitizen(const std::string& jobTitle, Citizen* citizen, Building* building);
    void releaseCitizenFromJob(Citizen* citizen);
    void listAllJobsInBuilding(const Building* building) const;
    // double collectAllTaxes();

private:
    std::vector<Building*> buildings;
    std::vector<Citizen*> citizens;
};

} // namespace YourNamespace

#endif // BUILDINGMANAGER_H