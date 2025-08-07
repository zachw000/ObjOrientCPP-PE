#pragma once

#include "../Manager.hpp"
#ifndef PROJECT_THREE_HPP
#define PROJECT_THREE_HPP

namespace Projects {
    class ProjectThree final : public Runtime::Project {
    private:
        unsigned short PID;
        std::string_view p_name = std::string_view("Largest Prime Factor");
    public:
        ProjectThree() : PID(3) {};
        explicit ProjectThree(const unsigned short id) : PID(id) {};
        ~ProjectThree() override;
        int run() override;
        [[nodiscard]] std::string_view getName() const override {
            return this->p_name;
        }

        unsigned short getID() override;
    };
};

#endif // PROJECT_THREE_HPP
