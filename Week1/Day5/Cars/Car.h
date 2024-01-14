#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <memory>

#include "CarType.h"
#include "Engine.h"

class Car {
private:
    std::string _carId{ "101" };
    std::string _carBrand{ "Jaguar" };
    float _carPrice{ 3000000.0f };
    enum CarType _carType { CarType::SEDAN };
    std::shared_ptr<Engine> _carEngine;

public:
    Car() = default;
    ~Car() = default;

    Car(std::string carId, std::string carBrand, float carPrice,
        CarType carType, std::shared_ptr<Engine> carEngine);

    std::string carId() const { return _carId; }

    std::string carBrand() const { return _carBrand; }

    float carPrice() const { return _carPrice; }

    enum CarType carType() const { return _carType; }

    std::shared_ptr<Engine> carEngine() const { return _carEngine; }

    friend std::ostream& operator<<(std::ostream& os, const Car& rhs);
};

#endif  // CAR_H
