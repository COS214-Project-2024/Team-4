//CONCRETE ITERATOR

#ifndef CITYTRAVERSER_h
#define CITYTRAVERSER_h

#include <vector>

#include "Traverser.h"
#include "Transportation.h"

class Transportation;
class Traverser;

class CityTraverser: public Traverser{
    private:

    public:
        CityTraverser();
        CityTraverser(Transportation* t);
        CityTraverser(CityTraverser* t);
        CityTraverser(std::vector<Transportation*> t);
        Transportation* operator++();
        Transportation* operator--();
        Transportation* operator+();
        Transportation* operator-();
        Transportation* operator*();
        Transportation* operator=(Transportation* t);
        Transportation* operator=(CityTraverser* t);
        Transportation* operator==(Transportation* t);
        Transportation* operator==(CityTraverser* t);
        Transportation* operator!=(Transportation* t);
        Transportation* operator!=(CityTraverser* t);
        ~CityTraverser();

};

#endif