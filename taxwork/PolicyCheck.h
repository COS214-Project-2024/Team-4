#ifndef POLICYCHECK_H
#define POLICYCHECK_H


#include <string>
#include "ResourceApprovalHandler.h"
using namespace std;
class PolicyCheck : ResourceApprovalHandler {


public:
	bool handleRequest(string type, int quantity);

	bool checkPolicy(string type);
};

#endif
