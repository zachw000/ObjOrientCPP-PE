#include "../../inc/Projects/ProjectTwo.hpp"
#include <iostream>
int Projects::ProjectTwo::run() {
    std::cout << "" << std::endl;

    unsigned short ID = this->getID();
    std::cout << "Project ID: " << ID << std::endl;

    return 0;
}

unsigned short Projects::ProjectTwo::getID() {
    return this->PID;
}

Projects::ProjectTwo::~ProjectTwo() {
    std::cout << "Destructor Reached" << std::endl;
}
