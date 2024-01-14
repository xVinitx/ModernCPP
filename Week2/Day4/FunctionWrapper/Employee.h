#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee
{
private:
    /*
        variable name 

            1. Prefix with _underscore
            2. camelCaseConvention

    */
    int _id;
    std::string _name;
    float _salary;
public:
/*
    Member functions in PascalCase.
    Enum Class in PascalCase.
    Filename in PascalCase.
*/

 Employee(int id, std::string name, float salary)
     : _id(id), _name(name), _salary(salary) {}

 ~Employee() {}

 int id() const { return _id; }

 float salary() const { return _salary; }
};

#endif // EMPLOYEE_H
