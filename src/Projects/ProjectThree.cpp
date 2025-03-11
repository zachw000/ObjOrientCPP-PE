#include "../../inc/Projects/ProjectThree.hpp"

int Projects::ProjectThree::run() {
    std::cout <<"" << std::endl;

    unsigned short ID = this->getID();
    std::cout << "Project ID: " << ID << std::endl;

    return 0;
}

unsigned short Projects::ProjectThree::getID() {
    return this->PID;
}

Projects::ProjectThree::~ProjectThree() {
    std::cout << "Destructor Reached" << std::endl;
}
