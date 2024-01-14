#include "Functionalities.h"
#include <iostream>

void CreateObjects(Container& data) {
    data.emplace_back(
        std::make_shared<Car>(
            "111", 
            "Maruti", 
            3500.0f,
            CarType::SEDAN,
            std::make_shared<Engine>(
                "101", 350, 92, EngineType::ICE
            )
        )
    );
    data.emplace_back(
        std::make_shared<Car>(
            "222", 
            "Alto", 
            1200.0f,
            CarType::SEDAN,
            std::make_shared<Engine>(
                "101", 350, 92, EngineType::ICE
            )
        )
    );
}

int EngineHorsepowerOFCar(const Container& data, const std::string id) {
    if (data.empty()) {
        throw std::runtime_error("Data is empty.");
    }

    for (const Pointer& ptr : data) {
        if (ptr->carId() == id) {
            return ptr->carEngine()->engineHorsepower();
        }
    }

    throw std::runtime_error("Id not found.");

}

Container EngineTorqueOver80(Container& data) {
    if (data.empty()) {
        throw std::runtime_error("Data is empty.");
    }

    Container result;

    for (Pointer& ptr : data) {
        if (ptr->carEngine()->enginetorque() > 80) {
            result.emplace_back(ptr);
        }
    }

    if (result.empty()) {
        throw std::runtime_error("No car with Torque above 80.");
    }

    return result;

}

Container MatchCarType(Container& data, CarType type) {
    if (data.empty()) {
        throw std::runtime_error("Data is empty.");
    }

    Container result;

    for (Pointer& ptr : data) {
        if (ptr->carType() == type) {
            result.emplace_back(ptr);
        }
    }

    if (result.empty()) {
        throw std::runtime_error("No car matches the given type.");
    }

    return result;
}

float AverageHorsePower(Container& data) {
    if (data.empty()) {
        throw std::runtime_error("Data is empty.");
    }

    float total = 0.0f;
    int count = 0;

    

    for(Pointer& ptr : data) {
        if((ptr->carEngine()->engineType() == EngineType::ICE) && (ptr->carPrice() > 100.0f)) {
            total += ptr->carEngine()->engineHorsepower();
            count++;
        }
    }

    if (!count) {
        throw std::runtime_error("Car with ");
    }


    return total / count;

}

std::string CarWithLowestPrice(Container& data) {
    if (data.empty()) {
        throw std::runtime_error("Data is empty.");
    }

    Pointer min = data.front();

    for(Pointer& ptr : data) {
        if(ptr->carPrice() < min->carPrice()) {
            min = ptr;
        }
    }

    return min->carId();


}

float CombinedPriceOfTwoCars(Car& car1, Car& car2) {
    return car1.carPrice() + car2.carPrice();
}
