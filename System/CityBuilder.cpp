#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

// Enum for building sizes
enum class BuildingSize {
    Small,
    Medium,
    Large
};

// Function to convert BuildingSize to a string for display
std::string sizeToString(BuildingSize size) {
    switch (size) {
        case BuildingSize::Small: return "Small";
        case BuildingSize::Medium: return "Medium";
        case BuildingSize::Large: return "Large";
        default: return "Unknown";
    }
}

// Forward declaration of Building to use in Citizen class
class Building;

// Citizen class
class Citizen {
public:
    Citizen(std::string name, int age) : name(name), age(age), job(nullptr), jobTitle("") {}
    std::string getName() const { return name; }
    int getAge() const { return age; }
    bool hasJob() const { return job != nullptr; }
    void assignJob(Building* building, std::string title);
    std::string getJobInfo() const;

private:
    std::string name;
    int age;
    Building* job;
    std::string jobTitle;
};

// Building class and subclasses
class Building {
public:
    Building(std::string name, BuildingSize size) : name(name), size(size) {}
    virtual ~Building() = default;
    virtual std::string getType() const = 0;
    std::string getName() const { return name; }
    std::string getSize() const { return sizeToString(size); }
    
    void addJobTitle(const std::string& title) { jobTitles.push_back(title); }
    bool hasJobTitle(const std::string& title) const;
    void removeJobTitle(const std::string& title);
    const std::vector<std::string>& getJobTitles() const { return jobTitles; }

private:
    std::string name;
    BuildingSize size;
    std::vector<std::string> jobTitles;  // List of available job titles
};

// Derived Building classes
class ResidentialBuilding : public Building {
public:
    ResidentialBuilding(std::string name, BuildingSize size) : Building(name, size) {}
    std::string getType() const override { return "Residential"; }
};

class CommercialBuilding : public Building {
public:
    CommercialBuilding(std::string name, BuildingSize size) : Building(name, size) {}
    std::string getType() const override { return "Commercial"; }
};

class IndustrialBuilding : public Building {
public:
    IndustrialBuilding(std::string name, BuildingSize size) : Building(name, size) {}
    std::string getType() const override { return "Industrial"; }
};

class LandmarkBuilding : public Building {
public:
    LandmarkBuilding(std::string name, BuildingSize size) : Building(name, size) {}
    std::string getType() const override { return "Landmark"; }
};

// Building methods
bool Building::hasJobTitle(const std::string& title) const {
    return std::find(jobTitles.begin(), jobTitles.end(), title) != jobTitles.end();
}

void Building::removeJobTitle(const std::string& title) {
    auto it = std::remove(jobTitles.begin(), jobTitles.end(), title);
    if (it != jobTitles.end()) {
        jobTitles.erase(it, jobTitles.end());
    }
}

// Citizen methods
void Citizen::assignJob(Building* building, std::string title) {
    job = building;
    jobTitle = title;
}

std::string Citizen::getJobInfo() const {
    return hasJob() ? ("Works as " + jobTitle + " at " + job->getName() + " (" + job->getType() + ")") : "Unemployed";
}

// Vectors to store buildings and citizens
std::vector<std::unique_ptr<Building>> buildings;
std::vector<std::unique_ptr<Citizen>> citizens;

// Function declarations for the UI
void displayMainMenu();
void manageBuildings();
void manageCitizens();
void addBuilding();
void addJobTitleToBuilding();
void removeBuilding();
void addCitizen();
void viewCitizens();
void assignJob();
void runpopsim();


int main() {
    bool exit = false;
    int choice;

    while (!exit) {
        displayMainMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                manageBuildings();
                break;
            case 2:
                manageCitizens();
                break;
            case 3:
                std::cout << "Exiting the City Builder Simulation.\n";
                exit = true;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    return 0;
}

void displayMainMenu() {
    std::cout << "\n--- City Builder Simulation ---\n";
    std::cout << "1. Manage Buildings\n";
    std::cout << "2. Manage Citizens\n";
    std::cout << "3. Exit\n";
}

// Building management functions
void manageBuildings() {
    int choice;
    std::cout << "\n--- Manage Buildings ---\n";
    std::cout << "1. Add Building\n";
    std::cout << "2. Add Job Title to Building\n";
    std::cout << "3. View All Buildings\n";
    std::cout << "4. Remove Building\n";
    std::cout << "Enter choice or 0 to return: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            addBuilding();
            break;
        case 2:
            addJobTitleToBuilding();
            break;
        case 3:
            if (buildings.empty()) {
                std::cout << "No buildings available.\n";
            } else {
                std::cout << "\nBuildings List:\n";
                for (const auto& building : buildings) {
                    std::cout << "Name: " << building->getName() 
                              << ", Type: " << building->getType() 
                              << ", Size: " << building->getSize() 
                              << ", Job Titles: ";
                    for (const auto& title : building->getJobTitles()) {
                        std::cout << title << " ";
                    }
                    std::cout << "\n";
                }
            }
            break;
        case 4:
            removeBuilding();
            break;
        default:
            std::cout << "Returning to main menu.\n";
            break;
    }
}

void addBuilding() {
    int type, sizeOption;
    std::string name;
    BuildingSize size;

    std::cout << "\nSelect Building Type:\n";
    std::cout << "1. Residential\n";
    std::cout << "2. Commercial\n";
    std::cout << "3. Industrial\n";
    std::cout << "4. Landmark\n";
    std::cout << "Enter type: ";
    std::cin >> type;

    std::cout << "Enter building name: ";
    std::cin.ignore(); // Ignore newline from previous input
    std::getline(std::cin, name);

    std::cout << "Select Building Size:\n";
    std::cout << "1. Small\n";
    std::cout << "2. Medium\n";
    std::cout << "3. Large\n";
    std::cout << "Enter size: ";
    std::cin >> sizeOption;

    switch (sizeOption) {
        case 1: size = BuildingSize::Small; break;
        case 2: size = BuildingSize::Medium; break;
        case 3: size = BuildingSize::Large; break;
        default:
            std::cout << "Invalid size selected. Defaulting to Small.\n";
            size = BuildingSize::Small;
            break;
    }

    switch (type) {
        case 1:
            buildings.push_back(std::make_unique<ResidentialBuilding>(name, size));
            std::cout << "Residential building added: " << name << "\n";
            break;
        case 2:
            buildings.push_back(std::make_unique<CommercialBuilding>(name, size));
            std::cout << "Commercial building added: " << name << "\n";
            break;
        case 3:
            buildings.push_back(std::make_unique<IndustrialBuilding>(name, size));
            std::cout << "Industrial building added: " << name << "\n";
            break;
        case 4:
            buildings.push_back(std::make_unique<LandmarkBuilding>(name, size));
            std::cout << "Landmark building added: " << name << "\n";
            break;
        default:
            std::cout << "Invalid building type selected.\n";
            break;
    }
}

void addJobTitleToBuilding() {
    std::string buildingName, jobTitle;
    std::cout << "Enter the building name to add a job title: ";
    std::cin.ignore();
    std::getline(std::cin, buildingName);

    auto it = std::find_if(buildings.begin(), buildings.end(),
                           [&buildingName](const std::unique_ptr<Building>& b) {
                               return b->getName() == buildingName;
                           });

    if (it != buildings.end()) {
        std::cout << "Enter the job title to add: ";
        std::getline(std::cin, jobTitle);
        (*it)->addJobTitle(jobTitle);
        std::cout << "Job title \"" << jobTitle << "\" added to \"" << buildingName << "\".\n";
    } else {
        std::cout << "Building \"" << buildingName << "\" not found.\n";
    }
}

void removeBuilding() {
    std::string name;
    std::cout << "Enter the name of the building to remove: ";
    std::cin.ignore(); // Ignore newline from previous input
    std::getline(std::cin, name);

    auto it = std::remove_if(buildings.begin(), buildings.end(),
                             [&name](const std::unique_ptr<Building>& building) {
                                 return building->getName() == name;
                             });

    if (it != buildings.end()) {
        buildings.erase(it, buildings.end());
        std::cout << "Building \"" << name << "\" has been removed.\n";
    } else {
        std::cout << "Building \"" << name << "\" not found.\n";
    }
}

// Citizen management functions
void manageCitizens() {
    int choice;
    std::cout << "\n--- Manage Citizens ---\n";
    std::cout << "1. Add Citizen\n";
    std::cout << "2. View All Citizens\n";
    std::cout << "3. Assign Job to Citizen\n";
    std::cout << "4. Run population growth\n";
    std::cout << "Enter choice or 0 to return: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            addCitizen();
            break;
        case 2:
            viewCitizens();
            break;
        case 3:
            assignJob();
            break;
        case 4:
            runpopsim();
            break;
        default:
            std::cout << "Returning to main menu.\n";
            break;
    }
}

void run1year(){

}

void run5years(){

}

void run10years(){

}

void run25years(){

}

void run50years(){

}

void  runpopsim(){
    int choice;
    std::cout << "\n--- Run Population Simulation ---\n";
    std::cout << "1. Run 1 year\n";
    std::cout << "2. Run 5 years\n";
    std::cout << "3. Run 10 years\n";
    std::cout << "4. Run 25 years\n";
    std::cout << "5. Run 50 years\n";
    std::cout << "Enter choice or 0 to return: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            run1year();
            break;
        case 2:
            run5years();
            break;
        case 3:
            run10years();
            break;
        case 4:
            run25years();
            break;
        case 5:
            run50years();
            break;
        default:
            std::cout << "Returning to main menu.\n";
            break;
    }
}

void addCitizen() {
    std::string name;
    int age;

    std::cout << "Enter citizen name: ";
    std::cin.ignore(); // Ignore newline from previous input
    std::getline(std::cin, name);

    std::cout << "Enter citizen age: ";
    std::cin >> age;

    citizens.push_back(std::make_unique<Citizen>(name, age));
    std::cout << "Citizen added: " << name << ", Age: " << age << "\n";
}

void viewCitizens() {
    if (citizens.empty()) {
        std::cout << "No citizens available.\n";
    } else {
        std::cout << "\nCitizens List:\n";
        for (const auto& citizen : citizens) {
            std::cout << "Name: " << citizen->getName() 
                      << ", Age: " << citizen->getAge() 
                      << ", Job: " << citizen->getJobInfo() << "\n";
        }
    }
}

void assignJob() {
    std::string citizenName, buildingName, jobTitle;
    std::cout << "Enter the citizen's name: ";
    std::cin.ignore();
    std::getline(std::cin, citizenName);

    auto citizenIt = std::find_if(citizens.begin(), citizens.end(),
                                  [&citizenName](const std::unique_ptr<Citizen>& c) {
                                      return c->getName() == citizenName;
                                  });

    if (citizenIt == citizens.end()) {
        std::cout << "Citizen \"" << citizenName << "\" not found.\n";
        return;
    }

    std::cout << "Enter the building name for the job: ";
    std::getline(std::cin, buildingName);

    auto buildingIt = std::find_if(buildings.begin(), buildings.end(),
                                   [&buildingName](const std::unique_ptr<Building>& b) {
                                       return b->getName() == buildingName;
                                   });

    if (buildingIt == buildings.end()) {
        std::cout << "Building \"" << buildingName << "\" not found.\n";
        return;
    }

    Building* building = buildingIt->get();
    if (building->getJobTitles().empty()) {
        std::cout << "No available job titles in \"" << buildingName << "\".\n";
        return;
    }

    std::cout << "Available job titles:\n";
    for (const auto& title : building->getJobTitles()) {
        std::cout << "- " << title << "\n";
    }
    std::cout << "Enter the job title to assign: ";
    std::getline(std::cin, jobTitle);

    if (!building->hasJobTitle(jobTitle)) {
        std::cout << "Job title \"" << jobTitle << "\" not available at \"" << buildingName << "\".\n";
        return;
    }

    (*citizenIt)->assignJob(building, jobTitle);
    building->removeJobTitle(jobTitle);
    std::cout << "Citizen \"" << citizenName << "\" assigned as \"" << jobTitle << "\" at \"" << buildingName << "\".\n";
}
