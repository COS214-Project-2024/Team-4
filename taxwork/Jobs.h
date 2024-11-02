#ifndef JOB_H
#define JOB_H

#include <string>
#include <iostream>

class Jobs{
private:
    std::string title;
    float income;
    int availablePositions;
    bool isEmployed;

public:
    Jobs(const std::string& title, float income, int availablePositions);

    std::string getTitle() const;
    float getIncome() const;
    int getAvailablePositions() const;
    bool getEmploymentStatus() const;

    // Methods to manage employment
    bool hireEmployee();
    void releaseEmployee();
    void displayJobInfo() const;
};

#endif