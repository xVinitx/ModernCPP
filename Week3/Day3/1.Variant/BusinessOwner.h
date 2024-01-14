#ifndef BUSINESSOWNER_H
#define BUSINESSOWNER_H

#include <iostream>

class BusinessOwner
{
private:
    
public:
    BusinessOwner(/* args */) {}
    ~BusinessOwner() {}

    void PayTax() {
        std::cout << "Business has to pay advance tax and GST every month/quarter" << "\n";
    }
};

#endif // BUSINESSOWNER_H
