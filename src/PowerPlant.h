#ifndef __POWERPLANT_H__
#define __POWERPLANT_H__

#include "Utility.h"

class PowerPlant {
    
    public:

        void generateElectricity(Building *building);

        void supplyPower(Building *building);

        PowerPlant();



};

#endif // __POWERPLANT_H__