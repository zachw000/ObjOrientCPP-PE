#include "../../inc/Projects/ProjectFour.hpp"
#include <iostream>
int Projects::ProjectFour::run() {
    std::cout << "" << std::endl;

    unsigned short ID = this->getID();
    std::cout << "Project ID: " << ID << std::endl;

    return 0;
}

unsigned short Projects::ProjectFour::getID() {
    return this->PID;
}

Projects::ProjectFour::~ProjectFour() {
    std::cout << "Destructor Reached" << std::endl;
}
