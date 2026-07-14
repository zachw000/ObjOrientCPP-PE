// filepath: /Users/mcuser/Documents/GitHub/ObjOrientCPP-PE/inc/Projects/ProjectSeven.hpp
#pragma once
#include "../Manager.hpp"
#include "../PEMath.hpp"
#ifndef PROJECT_SEVEN_HPP
#define PROJECT_SEVEN_HPP

namespace Projects {
    class ProjectSeven final : public Runtime::Project {
    private:
        unsigned short PID;
        const unsigned int limit = 10001; // Example limit for Project Seven
        std::string_view p_name = std::string_view("10,001st Prime Number");
    public:
        ProjectSeven() : PID(7) {};
        explicit ProjectSeven(const unsigned short id) : PID(id) {};
        ~ProjectSeven() override;
        virtual int run() override;

        std::string_view getName() const override {
            return this->p_name;
        }

        unsigned short getID() override;
    };
}
#endif // PROJECT_SEVEN_HPP