
#ifndef TRAVERSER_h
#define TRAVERSER_h

#include "Transportation.h"

class Transportation;

class Traverser {
    public:
        virtual bool operator++() = 0;
        virtual bool operator--() = 0;
        virtual Transportation* operator*() = 0;

};

#endif