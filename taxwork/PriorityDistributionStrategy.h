#ifndef PRIORITYDISTRIBUTIONSTRATEGY_H
#define PRIORITYDISTRIBUTIONSTRATEGY_H
#include"ResourceAllocationStrategy.h"
#include<string>
using namespace std ;
class PriorityDistributionStrategy : ResourceAllocationStrategy {


public:
	bool allocate(string type, int quantity);
};

#endif
