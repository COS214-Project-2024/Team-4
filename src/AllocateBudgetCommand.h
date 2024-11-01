#ifndef ALLOCATEBUDGETCOMMAND_H
#define ALLOCATEBUDGETCOMMAND_H

#include <string>

class AllocateBudgetCommand {
public:
    AllocateBudgetCommand(const std::string& department, double amount);
    void execute();

private:
    std::string department;
    double amount;
};

#endif // ALLOCATEBUDGETCOMMAND_H