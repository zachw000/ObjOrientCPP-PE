#pragma once
#include "../Manager.hpp"
#include <string_view>
#ifndef PROJECTS_PROJECTFOUR_HPP
#define PROJECTS_PROJECTFOUR_HPP

namespace Projects {
    class ProjectFour final : public Runtime::Project {
    private:
        unsigned short PID;
        std::string_view p_name = std::string_view("Largest Palindrome");
    public:
        ProjectFour() : PID(4) {};
        ProjectFour(unsigned short id) : PID(id) {};
        ~ProjectFour();
        virtual int run() override;
        std::string_view getName() const override {
            return this->p_name;
        }

        unsigned short getID();
    };
};

#endif //PROJECTS_PROJECTFOUR_HPP
