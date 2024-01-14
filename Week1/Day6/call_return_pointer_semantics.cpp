#include <iostream>
#include "Employee.h"
#include <memory>

using emp_pointer = std::shared_ptr<Employee>;

// Employee* Magic(Employee* emp) {
//     emp->setId(100);
//     return emp;
// }


// emp_pointer Magic (emp_pointer emp) {
//     emp->setId(100);
//     return emp;
// }


// Magic function takes one constant lvalue reference of type emp_pointer and returns void
// emp_pointer is a standard shared ptr to class Employee
void Magic(const emp_pointer& emp) {
    emp->setId(100);
}

int main() {
    // Employee* e1 = new Employee(111);
    // Employee* modified_e1 = Magic(e1);

    emp_pointer e1 = std::make_shared<Employee>(101);
    Magic(e1);
}