/**
 * @file FemaleCitizen.h
 * @brief Definition of the FemaleCitizen class.
 * @version 1.0
 * 
 * This file contains the definition of the FemaleCitizen class, which inherits from the Citizen class.
 * The FemaleCitizen class represents a female citizen with specific attributes and behaviors.
 */

#ifndef FEMALE_CITIZEN_H
#define FEMALE_CITIZEN_H

#include "Citizen.h"
#include <memory>

/**
 * @class FemaleCitizen
 * @brief A class representing a female citizen.
 * 
 * The FemaleCitizen class inherits from the Citizen class and provides a specific implementation
 * for female citizens. It includes a clone method to create a copy of the object.
 */
class FemaleCitizen : public Citizen {
public:
    /**
     * @brief Constructor for FemaleCitizen.
     * @param name The name of the female citizen.
     * @param age The age of the female citizen.
     */
    FemaleCitizen(const std::string& name, int age) : Citizen(name, age) {}

    /**
     * @brief Clone method to create a copy of the FemaleCitizen object.
     * @return A shared pointer to the cloned FemaleCitizen object.
     */
    std::shared_ptr<Citizen> clone() const override {
        return std::make_shared<FemaleCitizen>(*this);
    }
};

#endif // FEMALE_CITIZEN_H