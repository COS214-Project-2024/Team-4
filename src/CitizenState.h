/**
 * @file CitizenState.h
 * @brief Declaration of the CitizenState class.
 *
 * This file contains the declaration of the CitizenState class which handles the state of a citizen.
 * 
 * @version 1.0
 */

#ifndef CITIZENSTATE_H
#define CITIZENSTATE_H

class Citizen;

/**
 * @brief Abstract class representing the state of a citizen.
 */
class CitizenState {
public:
    /**
     * @brief Handles the state of a citizen.
     *
     * This function is responsible for managing the state of the given citizen.
     * 
     * @param citizen The citizen whose state is to be handled.
     */
    virtual void handleState(Citizen& citizen) const = 0;

    /**
     * @brief Virtual destructor for the CitizenState class.
     */
    virtual ~CitizenState() = default;
};

#endif // CITIZENSTATE_H