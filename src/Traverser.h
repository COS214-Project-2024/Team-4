
#ifndef TRAVERSER_h
#define TRAVERSER_h

#include "Transportation.h"

class Transportation;

class Traverser {
    public:
        virtual Transportation* operator++() = 0;
        virtual Transportation* operator--() = 0;
        virtual Transportation* operator+() = 0;
        virtual Transportation* operator-() = 0;
        virtual Transportation* operator*() = 0;

};

#endif