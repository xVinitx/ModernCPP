#ifndef EVCAR_H
#define EVCAR_H

#include <iostream>

#include "Vehicle.h"

class EvCar : public Vehicle {
   private:
    int _battery_capacity;

   public:
    EvCar(int id, std::string name, float price, VehicleType type, int capacity);

    EvCar(int id, std::string name, VehicleType type, int capacity);

    void CalculateRegistrationCharge();

    EvCar() = default;

    EvCar(const EvCar&) = delete;

    EvCar& operator=(const EvCar&) = delete;

    EvCar(EvCar&&) = delete;

    EvCar& operator=(EvCar&&) = delete;

    ~EvCar() = default;

    int batteryCapacity() const { return _battery_capacity; }

    friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);
};

#endif  // EVCAR_H
