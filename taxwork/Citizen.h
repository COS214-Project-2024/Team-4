#ifndef CITIZEN_H
#define CITIZEN_H

#include <string>
#include "Policy.h"
using namespace std;
class Citizen {

public:
	string name;
	int age;
	string RelStatus;
private:
	int id;
public:
	int satisfaction_Int;
	bool employmentstatus;
	bool adult;
	int numChildren;
	double BankBalance;
	string JobDesc;
	string EducationLevel;
	bool HealthInsurance;
private:
	double Income;
public:
	Citizen(string name, int age, string RelStatus, int id, int satisfaction_Int, bool employmentstatus, bool adult, int numChildren, double BankBalance, string JobDesc, string EducationLevel, bool HealthInsurance, double Income);
	
	void UpdateSatisfaction();

	void findJob();

	void FindLove();

	void updateAdultStatus();

	void updateBankBalance(double amount, bool increase);

	void updateEdu();

	void getState();

	void changeState();

	void updateTaxRate(double rate);

	void updatePolicy(Policy policy);
	// void updateServices(CityService service);
	double getIncome();
	void setIncome(double income);
};

#endif
