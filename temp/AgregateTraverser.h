#ifndef AGREGATETRAVERSER_H
#define AGREGATETRAVERSER_H

#include <vector>

#include "Transportation.h"
#include "CityTraverser.h"

class Transportation;

class AgregateTraverser {
    public:
        virtual CityTraverser* createCityTraverser() = 0;
        virtual CityTraverser* createCityTraverser(Transportation* t) = 0;
        virtual CityTraverser* createCityTraverser(CityTraverser *t) = 0;
        virtual CityTraverser* createCityTraverser(std::vector<Transportation*> t) = 0;
};

#endif