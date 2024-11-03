#ifndef CITIZEN_SATISFACTION_OBSERVER_H
#define CITIZEN_SATISFACTION_OBSERVER_H

#include "CitizenObserver.h"
#include "Citizen.h"
#include <iostream>

class CitizenSatisfactionObserver : public CitizenObserver {
public:
    void update(Citizen* citizen) override {
        // Adjust satisfaction and update state based on conditions
        citizen->updateSatisfaction(); // Update satisfaction
        citizen->checkAndUpdateState(); // Check and update state if necessary

        std::cout << citizen->getName() << "'s satisfaction updated to "
                  << citizen->getSatisfactionLevel() << "%, state updated.\n";
    }
};

#endif // CITIZEN_SATISFACTION_OBSERVER_H
