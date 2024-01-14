#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

#include "VehicleType.h"

class Vehicle {
   private:
    int _id;
    std::string _model_name;
    float _price;
    VehicleType _type;

   public:
    Vehicle(int id, std::string model, float price, VehicleType type);

    // 1. Default Construtor (deleted default constructor)
    Vehicle(/* args */) = delete;

    // 2. Copy Constructor (deleted copy constructor)
    Vehicle(const Vehicle&) = delete;

    // 3. Copy Assignment (deleted copy assignment)
    Vehicle& operator=(const Vehicle&) = delete;

    // 4. Move constructor (deleted move constructor)
    Vehicle(Vehicle&&) = delete;

    // 5. Move assignment (deleted move assignment)
    Vehicle& operator=(Vehicle&&) = delete;

    // 6. Destructor
    // ~Vehicle() = default;
    ~Vehicle() {
        //destructor gets executed before the actual release of memory happens
        std::cout << "~Vehicle() called.\n";
    }

    float price() { return _price; }

    int id() { return _id; }

    VehicleType type() const { return _type; }

    std::string modelName() const { return _model_name; }
    void setModelName(const std::string &model_name) { _model_name = model_name; }
};

#endif  // VEHICLE_H