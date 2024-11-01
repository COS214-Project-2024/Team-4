#ifndef BUDGETAPPROVAL_H
#define BUDGETAPPROVAL_H

#include <string>
#include"ResourceApprovalHandler.h"
using namespace std;

class BudgetApproval : public ResourceApprovalHandler {


public:
	bool handleRequest(string type, int quantity);

	bool checkBudget(string type, int quantity);
};

#endif
