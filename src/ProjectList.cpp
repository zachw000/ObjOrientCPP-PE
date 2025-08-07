#include "../inc/ProjectList.hpp"

void Projects::ProjectList::addProject(const int id, std::unique_ptr<Runtime::Project> project) {
    projectList[id] = std::move(project);
}

void Projects::ProjectList::removeProject(const int id) {
    projectList.erase(id);
}

void Projects::ProjectList::updateProject(const int id, std::unique_ptr<Runtime::Project> project) {
    projectList[id] = std::move(project);
}

std::unique_ptr<Runtime::Project> Projects::ProjectList::getProject(const int id) {
    return std::move(projectList[id]);
}

short Projects::ProjectList::getProjectCount() {
    return projectList.size();
}

Projects::ProjectList::ProjectList() {
    projectList[0] = std::make_unique<Projects::ProjectOne>(1);
    projectList[1] = std::make_unique<Projects::ProjectTwo>(2);
    projectList[2] = std::make_unique<Projects::ProjectThree>(3);
    projectList[3] = std::make_unique<Projects::ProjectFour>(4);
    projectList[4] = std::make_unique<Projects::ProjectFive>(5);
    projectList[5] = std::make_unique<Projects::ProjectSix>(6);

    projectList[0]->setID(1);
    projectList[1]->setID(2);
    projectList[2]->setID(3);
    projectList[3]->setID(4);
    projectList[4]->setID(5);
    projectList[5]->setID(6);
}
Projects::ProjectList::~ProjectList() {
    projectList.clear();
}
