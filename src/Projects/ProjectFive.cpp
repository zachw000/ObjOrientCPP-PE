#include "../../inc/Projects/ProjectFive.hpp"
#include <iostream>
int Projects::ProjectFive::run() {
    std::cout << this->p_name << std::endl;

    unsigned short ID = this->getID();
    std::cout << "Project ID: " << ID << std::endl;

    return 0;
}

unsigned short Projects::ProjectFive::getID() {
    return this->PID;
}

Projects::ProjectFive::~ProjectFive() {
    std::cout << "Destructor Reached" << std::endl;
}
