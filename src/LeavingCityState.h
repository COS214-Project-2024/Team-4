/**
 * @file LeavingCityState.h
 * @brief Definition of the LeavingCityState class.
 * @version 1.0
 * @date 2024-11-04
 * This file contains the definition of the LeavingCityState class, which handles the state
 * of a citizen preparing to leave the city.
 */

#ifndef LEAVINGCITYSTATE_H
#define LEAVINGCITYSTATE_H

#include "CitizenState.h"

/**
 * @class LeavingCityState
 * @brief Handles the state of a citizen preparing to leave the city.
 * 
 * The LeavingCityState class provides the implementation for handling the state of a citizen
 * who is preparing to leave the city.
 */
class LeavingCityState : public CitizenState {
public:
    /**
     * @brief Handles the state of a citizen preparing to leave the city.
     * @param citizen The citizen whose state is being handled.
     */
    void handleState(Citizen& citizen) const override;
};

#endif // LEAVINGCITYSTATE_H