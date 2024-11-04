// Jobs.h

#ifndef JOBS_H
#define JOBS_H

#include <memory>
#include "Income.h"
#include <string>
#include <memory>

class Jobs {
private:
    std::string title ;              // Job title, e.g., "Engineer", "Manager"
    bool occupied = false;            // Employment status; true if filled
    std::shared_ptr<Income> income;   // Income object associated with the job

public:
    // Constructor that initializes a job with a title and salary
    Jobs(const std::string& jobTitle, double salary);

    // Getters
    std::string getTitle() const { return title; }
    std::shared_ptr<Income> getIncome() const { return income; }
    bool isOccupied() const { return occupied; }
    void hireEmployee(); 
    void releaseEmployee() ;
    // Display job information (for debugging or user interaction)
    void displayJobInfo() const;
    void unOcuppy();
};

#endif // JOBS_H

