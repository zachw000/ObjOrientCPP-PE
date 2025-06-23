#pragma once
#include <memory>
#include "Projects/ProjectOne.hpp"
#include "Projects/ProjectTwo.hpp"
#include "Projects/ProjectThree.hpp"
#include "Projects/ProjectFour.hpp"
#include "Projects/ProjectFive.hpp"
#include "Projects/ProjectSix.hpp"
#ifndef PROJECTS_H
#define PROJECTS_H

namespace Projects {
    class ProjectList {
    private:
        std::unordered_map<int, std::unique_ptr<Runtime::Project>> projectList;
    public:
        ProjectList();

        ~ProjectList();

        void addProject(int id, std::unique_ptr<Runtime::Project> project);
        void removeProject(int id);
        void updateProject(int id, std::unique_ptr<Runtime::Project> project);
        int getProjectCount();
        std::unique_ptr<Runtime::Project> getProject(int id);
    };
};
#endif
