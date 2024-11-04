#include "PublicTransit.h"

PublicTransit::PublicTransit(char state, std::string route, char type) : Transportation(state, type) {
    this->route = route;
}

std::string PublicTransit::getRoute() {
    return route;
}