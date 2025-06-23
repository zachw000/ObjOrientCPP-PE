// filepath: /Users/mcuser/Documents/GitHub/ObjOrientCPP-PE/src/Projects/ProjectSix.cpp
#include "../../inc/Projects/ProjectSix.hpp"
#include <iostream>

/**
 * @author Your Name
 * @date 2025-05-12
 * @brief Project Six Description
 * @details This project does something interesting.
 * @warning This project is for educational purposes only and should not be used in production.
 * @license Apache-2.0 All rights reserved.
 * @see
 * 
 * Detailed explanation of the project goes here.
 */

int Projects::ProjectSix::run() {
    std::cout << "Running Project Six..." << std::endl;

    // Implement the logic for Project Six here

    std::cout << "Project Name: " << this->getName() << std::endl;
    std::cout << "Project ID: " << this->getID() << std::endl;

    return 0;
}

unsigned short Projects::ProjectSix::getID() {
    return this->PID;
}

Projects::ProjectSix::~ProjectSix() {
    return;
}