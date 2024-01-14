#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <memory>
#include <variant>
#include <vector>

#include "BusinessOwner.h"
#include "Employee.h"

// I need alias for shared pointer to Employee
using EmpPointer = std::shared_ptr<Employee>;

// I need alias for shared pointer to BusinessOwner
using BusinessPointer = std::shared_ptr<BusinessOwner>;

// I need alias for variants of above 2 pointers
using VType = std::variant<EmpPointer, BusinessPointer>;

// I finally would want a container of above variants
using Container = std::vector<VType>;

void CreateObjects(Container& data);

#endif  // FUNCTIONALITIES_H