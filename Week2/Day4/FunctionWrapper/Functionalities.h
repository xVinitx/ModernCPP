#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include "Employee.h"
#include <memory>
#include <functional>


using Pointer = std::shared_ptr<Employee>;
using Container = std::vector<Pointer>;

/*
    identifier AverageSalary is a variable name (name of an object)

    if a variable is declared in a file but has to be initialized
    in a separate file, suchvariables must be marked as "extern"
*/

// declaration

// extern std::function<float(Container&)> AverageSalary;

extern auto AverageSalary;

// this function returns the salaryof the employee whose id is given as second parameter
extern std::function<float(Container&, int)> SalaryGivenID;

// std::bind(SalaryGivenID, _1, 101);
// SalaryGivenId(data, 101);

// fn(data); // 101 should be hard coded (fixed)

 
#endif // FUNCTIONALITIES_H
