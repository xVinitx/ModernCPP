#ifndef DATAMODELLER_H
#define DATAMODELLER_H

#include<iostream>
#include <variant>
#include "Employee.h"
#include "BusinessOwner.h"
#include <memory>
#include <vector>

using BusinessPointer = std::unique_ptr<BusinessOwner>;
using EmpPointer = std::unique_ptr<Employee>;
using VType = std::variant<BusinessPointer, EmpPointer>;


class DataModeller{
    private:
    VType _instance;
    std::vector<float> _goodsPrices;    

    public:
        void operator()();
        
        //Default Constructor
        DataModeller()=delete;
        //Copy Constructor
        DataModeller(const DataModeller&)=delete;
        //Copy Assignment Operator
        DataModeller& operator=(const DataModeller&)=delete;
        //Move Constructor
        DataModeller(DataModeller&&)=delete;
        //Move Assignment Operator
        DataModeller& operator=(DataModeller&&)=delete;
        //Destructor
        ~DataModeller()=default;

        //Parameterized Constructor
        DataModeller(VType v, const std::vector<float>& prices);

        //Getter Functions
        const VType& instance() const { return _instance; }

        std::vector<float> goodsPrices() const { return _goodsPrices; }

        //Stream Output Operator
        friend std::ostream &operator<<(std::ostream &os, const DataModeller &rhs);

};

#endif // DATAMODELLER_H
