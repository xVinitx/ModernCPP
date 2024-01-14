#include "DieselCar.h"

DieselCar::DieselCar(int id, std::string name, float price, VehicleType type, int capacity) 
    : Vehicle(id, name, price, type), _fuel_capacity(capacity) {

}

DieselCar::DieselCar(int id, std::string name, VehicleType type, int capacity) 
    : Vehicle(id, name, type), _fuel_capacity(capacity) {

}

void DieselCar::CalculateRegistrationCharge()
{
    std::cout << "Tax on car: " << 0.18f * _price << std::endl;
}

std::ostream &operator<<(std::ostream &os, const DieselCar &rhs) {
    os << static_cast<const Vehicle &>(rhs)
       << " _fuel_capacity: " << rhs._fuel_capacity;
    return os;
}
