#include "createTraverser.h"

CityTraverser* CreateTraverser::createCityTraverser(){
    return new CityTraverser();
}

CityTraverser* CreateTraverser::createCityTraverser(Transportation* t){
    if(t == nullptr){
        return new CityTraverser();
    }

    return new CityTraverser(t);
}

CityTraverser* CreateTraverser::createCityTraverser(CityTraverser* t){
    if(t == nullptr){
        return new CityTraverser();
    }

    return new CityTraverser(t);
}

