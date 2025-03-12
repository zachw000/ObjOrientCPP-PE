#pragma once
#include <memory>
#include "Projects/ProjectOne.hpp"
#include "Projects/ProjectTwo.hpp"
#include "Projects/ProjectThree.hpp"
#include "Projects/ProjectFour.hpp"
#include "Projects/ProjectFive.hpp"
#ifndef PROJECTS_H
#define PROJECTS_H

namespace Projects {
    class ProjectList {
    private:
        std::unordered_map<int, std::unique_ptr<Runtime::Project>> projectList;
    public:
        ProjectList() {
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

        ~ProjectList() {
            this->projectList.clear();
        }

        void addProject(int id, std::unique_ptr<Runtime::Project> project);
        void removeProject(int id);
        void updateProject(int id, std::unique_ptr<Runtime::Project> project);
        int getProjectCount();
        std::unique_ptr<Runtime::Project> getProject(int id);
    };
};
#endif
