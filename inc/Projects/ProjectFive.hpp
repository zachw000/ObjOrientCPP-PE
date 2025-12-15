#pragma once
#include "../Manager.hpp"
#include <string_view>
#ifndef PROJECTS_PROJECTFIVE_HPP
#define PROJECTS_PROJECTFIVE_HPP

namespace Projects {
    class ProjectFive final : public Runtime::Project {
    private:
        unsigned short PID;
        std::string_view p_name = std::string_view("The Smallest Multiple");
    public:
        ProjectFive() : PID(5) {};
        explicit ProjectFive(const unsigned short id) : PID(id) {};
        ~ProjectFive() override;
        int run() override;
        [[nodiscard]] std::string_view getName() const override {
            return this->p_name;
        }

        unsigned short getID() override;
    };
};

#endif //PROJECTS_PROJECTFIVE_HPP
