// filepath: /Users/mcuser/Documents/GitHub/ObjOrientCPP-PE/inc/Projects/ProjectSix.hpp
#pragma once
#include "../Manager.hpp"
#ifndef PROJECT_SIX_HPP
#define PROJECT_SIX_HPP

namespace Projects {
    class ProjectSix final : public Runtime::Project {
    private:
        unsigned short PID;
        const unsigned int limit = 100000; // Example limit for Project Six
        std::string_view p_name = std::string_view("Project Six Example");
    public:
        ProjectSix() : PID(6) {};
        ProjectSix(unsigned short id) : PID(id) {};
        ~ProjectSix();
        virtual int run() override;

        std::string_view getName() const override {
            return this->p_name;
        }

        unsigned short getID();
    };
}
#endif // PROJECT_SIX_HPP