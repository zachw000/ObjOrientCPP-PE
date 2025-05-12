#include "../inc/ProjectList.hpp"

void Projects::ProjectList::addProject(int id, std::unique_ptr<Runtime::Project> project) {
    this->projectList[id] = std::move(project);
}

void Projects::ProjectList::removeProject(int id) {
    this->projectList.erase(id);
}

void Projects::ProjectList::updateProject(int id, std::unique_ptr<Runtime::Project> project) {
    this->projectList[id] = std::move(project);
}

std::unique_ptr<Runtime::Project> Projects::ProjectList::getProject(int id) {
    return std::move(this->projectList[id]);
}

int Projects::ProjectList::getProjectCount() {
    return this->projectList.size();
}

Projects::ProjectList::ProjectList() {
    this->projectList[0] = std::make_unique<Projects::ProjectOne>(1);
    this->projectList[1] = std::make_unique<Projects::ProjectTwo>(2);
    this->projectList[2] = std::make_unique<Projects::ProjectThree>(3);
    this->projectList[3] = std::make_unique<Projects::ProjectFour>(4);
    this->projectList[4] = std::make_unique<Projects::ProjectFive>(5);

    this->projectList[0]->setID(1);
    this->projectList[1]->setID(2);
    this->projectList[2]->setID(3);
    this->projectList[3]->setID(4);
    this->projectList[4]->setID(5);
}
Projects::ProjectList::~ProjectList() {
    this->projectList.clear();
}
