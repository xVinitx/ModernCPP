#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>

class Employee
{
private:
    /* data */
public:
    Employee(/* args */) {}
    ~Employee() {}

    void PayTax() {
        std::cout << "Employee tax" << "\n";
    }

};
#endif // EMPLOYEE_H
