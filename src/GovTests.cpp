// #include <iostream>
// #include "Government.h"
// #include "SetTaxCommand.h"
// #include "EnforcePolicyCommand.h"
// #include "AllocateBudgetCommand.h"
// #include "CollectTaxesCommand.h"
// #include "CityService.h"
// #include "Policy.h"

// int main() {
//     // Create a Government instance
//     Government government("City Government");

//     // Create a CityService instance
//     CityService cityService;
//     cityService.updateBudget(1000.0);

//     // Create a Policy instance
//     Policy policy;

//     // Create command instances
//     SetTaxCommand setTaxCommand(&government, 15.0);
//     EnforcePolicyCommand enforcePolicyCommand(&government, policy);
//     AllocateBudgetCommand allocateBudgetCommand(&government, cityService, 500.0);
//     CollectTaxesCommand collectTaxesCommand(&government);

//     // Execute commands
//     std::cout << "Executing SetTaxCommand..." << std::endl;
//     setTaxCommand.execute();

//     std::cout << "Executing EnforcePolicyCommand..." << std::endl;
//     enforcePolicyCommand.execute();

//     std::cout << "Executing AllocateBudgetCommand..." << std::endl;
//     allocateBudgetCommand.execute();

//     std::cout << "Executing CollectTaxesCommand..." << std::endl;
//     collectTaxesCommand.execute();

//     // Undo commands
//     std::cout << "Undoing SetTaxCommand..." << std::endl;
//     setTaxCommand.undo();

//     std::cout << "Undoing AllocateBudgetCommand..." << std::endl;
//     allocateBudgetCommand.undo();

//     std::cout << "Undoing CollectTaxesCommand..." << std::endl;
//     collectTaxesCommand.undo();

//     return 0;
// }