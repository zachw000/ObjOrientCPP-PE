#pragma once

#include "../Manager.hpp"

namespace Projects {
    class ProjectOne final : public Runtime::Project {
    private:
        unsigned short PID;
        std::string_view p_name = std::string_view("Multiples of 3 and 5");
        int limit = 1000;
        int multiples[2] = {3, 5};

        void setLimit(int newLimit);
        void setMultiples(int newMultiples[2]);
    public:
        ProjectOne() : PID(1) {};
        ProjectOne(unsigned short id) : PID(id) {};
        ~ProjectOne();
        virtual int run() override;

        std::string_view getName() const override {
            return this->p_name;
        }

        unsigned short getID();
    };
};
