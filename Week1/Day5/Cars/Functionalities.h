#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include "Car.h"
#include <memory>
#include <vector>

using Pointer = std::shared_ptr<Car>;

using Container = std::vector<Pointer>;

void CreateObjects(Container& data);

// a function to find and return the engineHorsepower of the engine instance for the Car whose carId is provided as an argument
int EngineHorsepowerOFCar(const Container& data, const std::string id);

// a function to find and return engine instances of all cars whose engineTorque is over 80Nm.
Container EngineTorqueOver80(Container& data);

// a function to find and return engine instances of all cars whose carType match with the type provided in the argument
Container MatchCarType(Container& data, CarType type);

// a function to find the average engineHorsepower of all Car instances satisfying the following conditions
//            engineType should be ICT
//            carPrice is over 1000000
float AverageHorsePower(Container& data);

// A function to find the carId of the car with the lowest carPrice 
std::string CarWithLowestPrice(Container& data);

// A function that accepts reference or pointers to 2 instances of Car and returns their combined price
float CombinedPriceOfTwoCars(Car& car1, Car& car2);

#endif // FUNCTIONALITIES_H
