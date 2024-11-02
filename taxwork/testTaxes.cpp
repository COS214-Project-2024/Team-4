#include <iostream>
#include "TaxSystem.h"
#include "TaxType.h"
#include "Citizen.h"
#include "MaleCitizen.h"
#include "FemaleCitizen.h"
#include "Building.h"
#include "BuildingManager.h"
#include "Income.h"
#include "Sales.h"
#include "Property.h"
#include "Government.h"
#include "TownHouse.h"

int main() {
    std::cout << "Running tax tests..." << std::endl;
    // Add your test cases here
    Government* government = new Government("DemocracyUnited");
    TaxSystem* taxSystem = new TaxSystem();
    taxSystem->addGovernment(government);

    TaxType* incomeTax = new Income(0.1);
    TaxType* salesTax = new Sales(0.05,0.1,0.13);
    TaxType* propertyTax = new Property(0.23,0.3,0.33);
    
    taxSystem->addTaxRate(incomeTax);


    return 0;
}