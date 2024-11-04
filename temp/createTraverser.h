#ifndef CREATETRAVERSER_H
#define CREATETRAVERSER_H

#include <vector>
#include "AgregateTraverser.h"
#include "Transportation.h"
#include "CityTraverser.h"

class AgregateTraverser;
class Transportation;
class CityTraverser;

class CreateTraverser : public AgregateTraverser{
    public:
        CityTraverser* createCityTraverser();
        CityTraverser* createCityTraverser(Transportation *t);
        CityTraverser* createCityTraverser(CityTraverser *t);

};

#endif