#include "Vehicle.h"

#include <iostream>

Vehicle::Vehicle(int id, std::string model, float price, VehicleType type)
    : _id(id), _model_name(model), _price(price), _type(type) {}
