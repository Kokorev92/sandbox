#pragma once

#include <string>

class Worker {
public:
    Worker(std::string name, uint16_t year)
            : name_(name), employment_year_(year) {}

    ~Worker() = default;

    std::string get_name();
    uint16_t    get_employment_year();

private:
    std::string name_;

    uint16_t employment_year_;
};