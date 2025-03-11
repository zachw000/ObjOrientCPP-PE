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
