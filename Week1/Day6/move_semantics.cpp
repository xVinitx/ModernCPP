/*
    I am creating a function magic
    It needs to accept one integer "data"

    scenario 1:
    copy and create duplicated data value to preserve original value 
    inside data and yet perform operations on the copy inside magic


    scenario 2:
    I have "temporary" integer which needs to be passed to magic.
    Magic would perform operations like modification on the integer 
    and return the modified value
    
    Scenario 2A - pass integer rvalue reference and returns modified data by value 
    - 
*/

/*
    This overload of magic accepts one integer by rvalue reference 
    and returns one integer by value
*/
#include "Employee.h"
#include <memory>

int Magic(int&& data) {

}

Employee Magic(Employee&& data) {

}

std::shared_ptr<Employee> Magic(std::shared_ptr<Employee>&& data){

}

int main() {
    Magic(10);
    Magic(Employee(101));
    Magic(std::make_shared<Employee> (101));
}