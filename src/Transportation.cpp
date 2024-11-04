#include "Transportation.h"

Transportation::Transportation(char state, char type) {
    switch (state)
    {
    case 'P':
        this->state = new Peak();
        break;
    
    case 'N':
        this->state = new NonPeak();
        break;

    case 'L':
        this->state = new LunchRush();
        break;

    default:
        break;
    };

    this->type = type;

}

float Transportation::getTrafficFlow() {
    return this->state->getTrafficFlow();
}

bool Transportation::setState(char state) {
    switch (state)
    {
    case 'P':
        delete this->state;
        this->state = nullptr; 
        this->state = new Peak();
        return true;
        break;
    
    case 'N':
        delete this->state;
        this->state = nullptr;
        this->state = new NonPeak();
        return true;
        break;

    case 'L':
        delete this->state;
        this->state = nullptr;
        this->state = new LunchRush();
        return true;
        break;

    default:
        return false;
        break;
    };
    
}

char Transportation::getType() {
    return this->type;
}

Transportation::~Transportation() {
    delete this->state;
    this->state = nullptr;
};