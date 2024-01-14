#include "HybridCar.h"

HybridCar::HybridCar(int id, std::string name, float price, VehicleType type, int fcapacity, int bcapacity)
    : Vehicle(id, name, price, type), _fuel_capacity(fcapacity), _battery_capacity(bcapacity) {

}

void HybridCar::CalculateRegistrationCharge()
{
    std::cout << "Tax on car: " << 0.18f * _price << std::endl;
}

// HybridCar::HybridCar(int id, std::string name, VehicleType type, int fcapacity, int bcapacity)
//     : Vehicle(id, name, type), _fuel_capacity(fcapacity), _battery_capacity(bcapacity) {
// }

std::ostream& operator<<(std::ostream& os, const HybridCar& rhs) {
    os << "_fuel_capacity: " << rhs._fuel_capacity
        << " _battery_capacity: " << rhs._battery_capacity;
    return os;
}

