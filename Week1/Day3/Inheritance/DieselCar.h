#ifndef DIESELCAR_H
#define DIESELCAR_H

#include <iostream>
#include "Vehicle.h"

class DieselCar : public Vehicle {
   private:
    int _fuel_capacity;

   public:
    DieselCar(int id, std::string name, float price, VehicleType type,
              int capacity);

    DieselCar(int id, std::string name, VehicleType type, int capacity);

    void CalculateRegistrationCharge();

    DieselCar() = default;

    DieselCar(const DieselCar&) = delete;

    DieselCar& operator=(const DieselCar&) = delete;

    DieselCar(DieselCar&&) = delete;

    DieselCar& operator=(DieselCar&&) = delete;

    ~DieselCar() = default;

    int fuelCapacity() const { return _fuel_capacity; }

    friend std::ostream &operator<<(std::ostream &os, const DieselCar &rhs);
};

#endif  // DIESELCAR_H
