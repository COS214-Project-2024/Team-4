#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Builder.h"
#include <string>
using namespace std;

/**
 * @class Director
 * @brief The Director class for constructing buildings.
 * 
 * This class provides methods to construct buildings of different sizes using a Builder object.
 * 
 * @version 1.0
 * @date 2023-10-01
 */
class Director {

private:
    Builder* builder; /**< Pointer to the Builder object used for constructing buildings. */

public:
    /**
     * @brief Sets the builder object.
     * 
     * This method sets the builder object that will be used to construct buildings.
     * 
     * @param builder Reference to a Builder object.
     */
    void setBuilder(Builder& builder);

    /**
     * @brief Constructs a small building.
     * 
     * This method constructs a small building with predefined parameters.
     * 
     * @return std::unique_ptr<Building> Pointer to the newly constructed small building.
     */
    std::unique_ptr<Building> constructSmallBuilding();

    /**
     * @brief Constructs a medium building.
     * 
     * This method constructs a medium building with predefined parameters.
     * 
     * @return std::unique_ptr<Building> Pointer to the newly constructed medium building.
     */
    std::unique_ptr<Building> constructMediumBuilding();

    /**
     * @brief Constructs a large building.
     * 
     * This method constructs a large building with predefined parameters.
     * 
     * @return std::unique_ptr<Building> Pointer to the newly constructed large building.
     */
    std::unique_ptr<Building> constructLargeBuilding();
};

#endif // DIRECTOR_H