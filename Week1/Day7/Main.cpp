#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include "Employee.h"

using EmpPointer = std::shared_ptr<Employee>;
using ListContainer = std::list<EmpPointer>;
using VectorContainer = std::vector<EmpPointer>;

void CreateObjects(ListContainer& l1, VectorContainer& v1) {
    l1.emplace_back(
        std::make_shared<Employee>(101)
    );

    l1.emplace_back(
        std::make_shared<Employee>(102)
    );
    
    l1.emplace_back(
        std::make_shared<Employee>(103)
    );

    v1.emplace_back(
        std::make_shared<Employee>(201)
    );
    
    v1.emplace_back(
        std::make_shared<Employee>(202)
    );
    
    v1.emplace_back(
        std::make_shared<Employee>(203)
    );
}


int main() {
    ListContainer l1;
    VectorContainer v1;
    CreateObjects(l1, v1);
}


