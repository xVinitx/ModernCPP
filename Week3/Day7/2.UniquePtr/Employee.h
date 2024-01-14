#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include "EmployeeType.h"

class Employee{
    private:
        std::string _name;
        EmployeeType _type;
        float _salary;

    public:
        //Default Constructor
        Employee()=delete;

        //Copy Constructor
        Employee(const Employee&)=delete;

        //Copy Assignment Operator
        Employee& operator=(const Employee&)=delete;

        //Move Constructor
        Employee(Employee&&)=delete;

        //Move Assignment Operator
        Employee& operator=(Employee&&)=delete;

        //Destructor
        ~Employee()=default;

        //Parameterized Constructor
        Employee(std::string name, EmployeeType type, float salary);

        std::string name() const { return _name; }

        EmployeeType type() const { return _type; }

        float salary() const { return _salary; }

        friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);

        //Getter Functions

        //Stream Output Operator
};

#endif // EMPLOYEE_H
