#include "../../inc/Projects/ProjectFour.hpp"
#include <iostream>
int Projects::ProjectFour::run() {
    std::cout << "" << std::endl;

    const unsigned short ID = this->getID();
    std::cout << "Project ID: " << ID << std::endl;

    return 0;
}

unsigned short Projects::ProjectFour::getID() {
    return this->PID;
}

Projects::ProjectFour::~ProjectFour() {
    return;
}
