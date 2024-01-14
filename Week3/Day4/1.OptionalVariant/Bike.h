#ifndef BIKE_H
#define BIKE_H

#include <iostream>
#include "VehicleType.h"

class Bike
{
private:
    std::string _id;
    float _price;
    // BikeType _type;
    VehicleType _type;
    
public:
    Bike() = default;
    Bike(Bike &&) = default;
    Bike(const Bike &) = default;
    Bike &operator=(Bike &&) = default;
    Bike &operator=(const Bike &) = default;
    ~Bike() = default;

    Bike(std::string id, float price, VehicleType type);

    std::string id() const { return _id; }

    float price() const { return _price; }

    VehicleType type() const { return _type; }

    friend std::ostream &operator<<(std::ostream &os, const Bike &rhs);
};

#endif // BIKE_H
