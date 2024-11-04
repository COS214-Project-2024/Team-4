#ifndef __POWERPLANT_H
#define __POWERPLANT_H

#include "Utility.h"
#include "UtilityMediator.h"
#include "ResourceType.h"

class UtilityMediator;

class PowerPlant : public Utility {
    private:
        UtilityMediator* mediator;
    
    public:

        PowerPlant(UtilityMediator* mediator);

        //void generateElectricity(Building *building);

        void registerBuilding(Building* building) override;

        void supplyResources(Building *building) override;

        //void adjustForCitizen(Citizen* citizen) override;
        //PowerPlant();



};

#endif // __POWERPLANT_H