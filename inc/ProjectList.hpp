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
        inline static std::unordered_map<int, std::unique_ptr<Runtime::Project>> projectList;
    public:
        ProjectList();

        ~ProjectList();
        // Static method to register a project with a unique ID
        static bool registerProject(int id, std::unique_ptr<Runtime::Project> project) {
            if (projectList.find(id) != projectList.end()) {
                return false; // Project ID already exists
            }
            projectList[id] = std::move(project);
            return true;
        }

        static void addProject(int id, std::unique_ptr<Runtime::Project> project);
        static void removeProject(int id);
        static void updateProject(int id, std::unique_ptr<Runtime::Project> project);
        static short getProjectCount() ;
        static std::unique_ptr<Runtime::Project> getProject(int id);
    };
};
#endif
