#pragma once
#include "Student.hpp"
#include <vector>
#include <string>

class IDataBase
{
public:
    virtual std::vector<Student> load() = 0;
    virtual void save(const std::vector<Student> &data) = 0;
    virtual ~IDataBase() = default;
};
