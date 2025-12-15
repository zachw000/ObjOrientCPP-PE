#pragma once
#include "../Manager.hpp"
#ifndef PROJECT_TWO_HPP
#define PROJECT_TWO_HPP

namespace Projects {
    class ProjectTwo final : public Runtime::Project {
    private:
        unsigned short PID;
        const unsigned int limit = 4000000; // Limit for Fibonacci numbers
        std::string_view p_name = std::string_view("Even Fibonacci numbers");
    public:
        ProjectTwo() : PID(2) {};
        ProjectTwo(unsigned short id) : PID(id) {};
        ~ProjectTwo() override;
        virtual int run() override;

        std::string_view getName() const override {
            return this->p_name;
        }

        unsigned short getID() override;
    };
}
#endif // PROJECT_TWO_HPP
