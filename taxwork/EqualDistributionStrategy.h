#ifndef EQUALDISTRIBUTIONSTRATEGY_H
#define EQUALDISTRIBUTIONSTRATEGY_H

#include "ResourceAllocationStrategy.h"
#include <string>
using namespace std ;

class EqualDistributionStrategy : public ResourceAllocationStrategy {


public:
	bool allocate(string type, int quantity);
};

#endif
