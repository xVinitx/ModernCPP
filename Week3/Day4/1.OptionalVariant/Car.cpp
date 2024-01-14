#include "Car.h"

Car::Car(std::string id, float price, VehicleType type) 
: _id(id), _price(price), _type(type) {

}


std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_id: " << rhs._id
       << " _price: " << rhs._price
       << " _carType: " << static_cast<int>(rhs._type);
    return os;
}
