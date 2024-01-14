#include "Functionalities.h" 
#include "PetrolCar.h"
#include "EvCar.h"
#include "DieselCar.h"
#include "HybridCar.h"
#include <memory>

void CreateObjects(Container& data) {

    // Petrol Car
    data.emplace_back(
        std::make_shared<PetrolCar>(101, "City", 140.0f, VehicleType::PERSONAL, 40)
    );

    data.emplace_back(
        std::make_shared<PetrolCar>(101, "Dzire", 90.0f, VehicleType::TRANSPORT, 37)
    );

    data.emplace_back(
        std::make_shared<PetrolCar>(101, "Baleno", 950.0f, VehicleType::PERSONAL, 37)
    );

    // Diesel Car
    data.emplace_back(
        std::make_shared<DieselCar>(101, "City", 1400.0f, VehicleType::PERSONAL, 40)
    );

    data.emplace_back(
        std::make_shared<DieselCar>(101, "Dzire", 900.0f, VehicleType::TRANSPORT, 37)
    );

    data.emplace_back(
        std::make_shared<DieselCar>(101, "Baleno", 950.0f, VehicleType::PERSONAL, 37)
    );

    //EV Car
    data.emplace_back(
        std::make_shared<EvCar>(201, "Nexon", 150.0f, VehicleType::PERSONAL, 40)
    );

    data.emplace_back(
        std::make_shared<EvCar>(202, "Eco", 130.0f, VehicleType::TRANSPORT, 60)
    );

    data.emplace_back(
        std::make_shared<EvCar>(203, "Mah400", 160.0f, VehicleType::TRANSPORT, 40)
    );

    // Hybrid Cars
    data.emplace_back(
        std::make_shared<HybridCar>(101, "GrandVitara", 190.0f, VehicleType::PERSONAL, 45, 1)
    );

    data.emplace_back(
        std::make_shared<HybridCar>(101, "UrbanCruiser", 16.0f, VehicleType::PERSONAL, 37, 2)
    );

    data.emplace_back(
        std::make_shared<HybridCar>(101, "Hycross", 300.0f, VehicleType::PERSONAL, 52, 2)
    );
}

float AveragePrice(Container& data) {
    float sum = 0.0f;

    for(const auto &avg : data) {
        sum = sum + avg->price();

    }
    float avg = sum / data.size();
    return avg;
}

void Display(Container& data) {
    for(Pointer& ptr : data) {
        if(auto petrol = std::dynamic_pointer_cast<PetrolCar>(ptr)) {
            std::cout << *petrol << "\n";
        }
        else if (auto diesel = std::dynamic_pointer_cast<DieselCar>(ptr)) {
            std::cout << *diesel << "\n";
        }
        else if (auto ev = std::dynamic_pointer_cast<EvCar>(ptr)) {
            std::cout << *ev << "\n";
        }
        else if (auto hybrid = std::dynamic_pointer_cast<HybridCar>(ptr)) {
            std::cout << *hybrid << "\n";
        }

    }
}
