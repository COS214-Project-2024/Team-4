/**
 * @file MaleCitizen.h
 * @brief Definition of the MaleCitizen class.
 * @version 1.0
 * 
 * This file contains the definition of the MaleCitizen class, which inherits from the Citizen class.
 * The MaleCitizen class represents a male citizen with specific attributes and behaviors.
 */

#ifndef MALE_CITIZEN_H
#define MALE_CITIZEN_H

#include "Citizen.h"
#include <memory>

/**
 * @class MaleCitizen
 * @brief A class representing a male citizen.
 * 
 * The MaleCitizen class inherits from the Citizen class and provides a specific implementation
 * for male citizens. It includes a clone method to create a copy of the object.
 */
class MaleCitizen : public Citizen {
public:
    /**
     * @brief Constructor for MaleCitizen.
     * @param name The name of the male citizen.
     * @param age The age of the male citizen.
     */
    MaleCitizen(const std::string& name, int age) : Citizen(name, age) {}

    /**
     * @brief Clone method to create a copy of the MaleCitizen object.
     * @return A shared pointer to the cloned MaleCitizen object.
     */
    std::shared_ptr<Citizen> clone() const override {
        return std::make_shared<MaleCitizen>(*this);
    }
};

#endif // MALE_CITIZEN_H