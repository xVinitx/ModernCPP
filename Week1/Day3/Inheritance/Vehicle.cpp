#include "Vehicle.h"

std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _price: " << rhs._price
       << " _type: " << static_cast<int>(rhs._type);
    return os;
}

Vehicle::Vehicle(int id, std::string name, float price, VehicleType type)
    : Vehicle(id, name, type) {
    // [constructor delegation] and member list initialization canot be used in the same file.
    _price = price;
}    


Vehicle::Vehicle(int id, std::string name, VehicleType type) 
    :_id(id), _name(name), _type(type)
{

}
