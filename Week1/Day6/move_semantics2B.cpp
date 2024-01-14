/*
scenario 2 :
            I have "temporary" integer which needs to be passed to
            magic.Magic would perform operations like modification on the
            integer and return the modified value

            Scenario 2B: Pass data by value and return data by value

            - lvalue reference accepts variable and rejects temperory.
            - rvalue reference accepts temperory and accepts variable.

*/

#include <memory>

#include "Employee.h"


int Magic(int data) {

}


Employee Magic(Employee data) {

}

std::shared_ptr<Employee> Magic(std::shared_ptr<Employee>&& data) {

}

int main() {
    Magic(10);
    int n1 = 10;
    Magic(n1);
    ///////////////////////////

    Magic(Employee(101));
    Employee e1(101);
    Magic(e1);
    ///////////////////////////

    Magic(std::make_shared<Employee>(101));
    std::shared_ptr<Employee> ptr = std::make_shared<Employee>(100);
}