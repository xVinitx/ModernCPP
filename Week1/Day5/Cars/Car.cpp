#include "Car.h"

Car::Car(std::string carId, std::string carBrand, float carPrice,
         CarType carType, std::shared_ptr<Engine> carEngine)
    : _carId(carId),
      _carBrand(carBrand),
      _carPrice(carPrice),
      _carType(carType),
      _carEngine(carEngine) {}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << " _carId:     " << rhs._carId << "\n"
       << " _carBrand:  " << rhs._carBrand << "\n"
       << " _carPrice:  " << rhs._carPrice << "\n"
       << " _carType:   " << static_cast<int>(rhs._carType) << "\n"
       << " _carEngine: " << *rhs._carEngine << "\n";
    return os;
}

