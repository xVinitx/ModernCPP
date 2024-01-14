#include "BusinessOwner.h"

BusinessOwner::BusinessOwner(float expense, float revenue,
                             std::string registeredBusinessName,
                             BusinessType type) 
                             : _expense(expense), _revenue(revenue), 
                             _registeredBusinessName(registeredBusinessName) {}

std::ostream &operator<<(std::ostream &os, const BusinessOwner &rhs) {
    os << "_expense: " << rhs._expense
       << " _revenue: " << rhs._revenue
       << " _registeredBusinessName: " << rhs._registeredBusinessName
       << " _type: " << static_cast<int>(rhs._type);
    return os;
}

