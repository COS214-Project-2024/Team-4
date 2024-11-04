/**
 * @file createTraverser.cpp
 * @brief Implementation of the CreateTraverser class for creating CityTraverser objects.
 * 
 * This file contains the implementation of the CreateTraverser class, which provides
 * methods to create instances of CityTraverser with different parameters.
 * 
 * @version 1.0
 * @date 2023-10-01
 */

#include "createTraverser.h"

/**
 * @brief Creates a new CityTraverser object.
 * 
 * This method creates a new instance of the CityTraverser class without any parameters.
 * 
 * @return CityTraverser* Pointer to the newly created CityTraverser object.
 */
CityTraverser* CreateTraverser::createCityTraverser(){
    return new CityTraverser();
}

/**
 * @brief Creates a new CityTraverser object with a Transportation parameter.
 * 
 * This method creates a new instance of the CityTraverser class with a Transportation
 * parameter. If the parameter is null, it creates a CityTraverser without any parameters.
 * 
 * @param t Pointer to a Transportation object.
 * @return CityTraverser* Pointer to the newly created CityTraverser object.
 */
CityTraverser* CreateTraverser::createCityTraverser(Transportation* t){
    if(t == nullptr){
        return new CityTraverser();
    }

    return new CityTraverser(t);
}

/**
 * @brief Creates a new CityTraverser object by copying another CityTraverser object.
 * 
 * This method creates a new instance of the CityTraverser class by copying an existing
 * CityTraverser object. If the parameter is null, it creates a CityTraverser without any parameters.
 * 
 * @param t Pointer to a CityTraverser object.
 * @return CityTraverser* Pointer to the newly created CityTraverser object.
 */
CityTraverser* CreateTraverser::createCityTraverser(CityTraverser* t){
    if(t == nullptr){
        return new CityTraverser();
    }

    return new CityTraverser(t);
}