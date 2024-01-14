#include "EvCar.h"

EvCar::EvCar(int id, std::string name, float price, VehicleType type, int capacity)
    : Vehicle(id, name, price, type), _battery_capacity(capacity) {

}

EvCar::EvCar(int id, std::string name, VehicleType type, int capacity) 
    : Vehicle(id, name, type), _battery_capacity(capacity) {

}

void EvCar::CalculateRegistrationCharge() {
    std::cout << "Tax on EV Car is 9%: " << 0.09f * _price;
}

std::ostream &operator<<(std::ostream &os, const EvCar &rhs) {
    os << static_cast<const Vehicle &>(rhs)
       << " _battery_capacity: " << rhs._battery_capacity;
    return os;
}
