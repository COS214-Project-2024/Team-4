#include "Citizen.h"

Citizen::Citizen(string name, int age, string RelStatus, int id, int satisfaction_Int, bool employmentstatus, bool adult, int numChildren, double BankBalance, string JobDesc, string EducationLevel, bool HealthInsurance, double Income) {
	this->name = name;
	this->age = age;
	this->RelStatus = RelStatus;
	this->id = id;
	this->satisfaction_Int = satisfaction_Int;
	this->employmentstatus = employmentstatus;
	this->adult = adult;
	this->numChildren = numChildren;
	this->BankBalance = BankBalance;
	this->JobDesc = JobDesc;
	this->EducationLevel = EducationLevel;
	this->HealthInsurance = HealthInsurance;
	this->Income = Income;
}

void Citizen::UpdateSatisfaction() {
	// TODO - implement Citizen::UpdateSatisfaction
	throw "Not yet implemented";
}

void Citizen::findJob() {
	// TODO - implement Citizen::findJob
	throw "Not yet implemented";
}

void Citizen::FindLove() {
	// TODO - implement Citizen::FindLove
	throw "Not yet implemented";
}

void Citizen::updateAdultStatus() {
	// TODO - implement Citizen::updateAdultStatus
	throw "Not yet implemented";
}

void Citizen::updateBankBalance(double amount, bool increase) {
	if (increase) {
		BankBalance += amount;
	}
	else {
		BankBalance -= amount;
	}
}

void Citizen::updateEdu() {
	// TODO - implement Citizen::updateEdu
	throw "Not yet implemented";
}

void Citizen::getState() {
	// TODO - implement Citizen::getState
	throw "Not yet implemented";
}

void Citizen::changeState() {
	// TODO - implement Citizen::changeState
	throw "Not yet implemented";
}

void Citizen::updateTaxRate(double rate) {
	// TODO - implement Citizen::updateTaxRate
	throw "Not yet implemented";
}

void Citizen::updatePolicy(Policy policy) {
	// TODO - implement Citizen::updatePolicy
	throw "Not yet implemented";
}

// void Citizen::updateServices(CityService service) {
// 	// TODO - implement Citizen::updateServices
// 	throw "Not yet implemented";
// }

double Citizen::getIncome() {
	return Income;
}
void Citizen::setIncome(double income) {
	Income = income;
}
