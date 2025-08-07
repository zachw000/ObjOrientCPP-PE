#include "../../inc/Projects/ProjectThree.hpp"
#include <iostream>

int Projects::ProjectThree::run() {
    std::cout <<"Largest Prime Factor (Problem 3)" << std::endl;

    const unsigned short ID = this->getID();
    std::cout << "Project ID: " << ID << std::endl;

    return 0;
}

unsigned short Projects::ProjectThree::getID() {
    return this->PID;
}

Projects::ProjectThree::~ProjectThree() {
    // TODO: Delete this->factors<int> when implemented
    return;
}
