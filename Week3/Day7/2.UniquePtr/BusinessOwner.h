#ifndef BUSINESSOWNER_H
#define BUSINESSOWNER_H

#include<iostream>
#include "BusinessType.h"

class BusinessOwner{
    private:
        float _expense;
        float _revenue;
        std::string _registeredBusinessName;
        BusinessType _type;

    public:
        //Default Constructor
        BusinessOwner()=delete;

        //Copy Constructor
        BusinessOwner(const BusinessOwner&)=delete;

        //Copy Assignment Operator
        BusinessOwner& operator=(const BusinessOwner&)=delete;

        //Move Constructor
        BusinessOwner(BusinessOwner&&)=delete;

        //Move Assignment Operator
        BusinessOwner& operator=(BusinessOwner&&)=delete;

        //Destructor
        ~BusinessOwner()=default;

        //Parameterized Constructor
        BusinessOwner(float expense, float revenue, std::string registeredBusinessName, BusinessType type);

        // Getter Functions

        float expense() const { return _expense; }

        float revenue() const { return _revenue; }

        std::string registeredBusinessName() const { return _registeredBusinessName; }

        BusinessType type() const { return _type; }

        friend std::ostream &operator<<(std::ostream &os, const BusinessOwner &rhs);


        //Stream Output Operator
        
};

#endif // BUSINESSOWNER_H
