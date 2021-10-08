#pragma once

#include <string>

class Worker {
public:
    Worker(std::string name, std::string position, uint16_t year)
            : name_(name), position_(position), employment_year_(year) {}

    ~Worker() = default;

    /**
     * \brief Возвращет имя сотрудника
     *
     * \return std::string
     */
    std::string get_name();

    std::string get_position();

    uint16_t get_employment_year();

private:
    std::string name_;
    std::string position_;

    uint16_t employment_year_;
};