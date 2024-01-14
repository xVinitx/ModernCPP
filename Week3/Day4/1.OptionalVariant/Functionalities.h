#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Bike.h"
#include "Car.h"

#include <iostream>
#include <list>
#include <memory>
#include <variant>
#include <optional>

using BikePointer = std::shared_ptr<Bike>;
using CarPointer = std::shared_ptr<Car>;

using VType = std::variant<BikePointer, CarPointer>;

using Container = std::list<VType>;

/*
    - Taking an empty container by lvalue reference and fill it with variant objects
    - It should return void
*/
void CreateObjects(Container& data);

/*
    Average price can be found using visit and total
*/
float AveragePrice(const Container& data);

/*
    Find instance with minimum price (all vehicles have prices which are unique)
*/

VType InstanceWithMinimumPrice(const Container& data);

/*
    Check if given ID is present in any of the instance
*/

bool IfIDExists(const Container& data, std::string id);

/*
    Return all instances whose type matches with type passed
*/
// template <typename T>

std::optional<Container> InstancesMatchingType(const Container& data, VehicleType type);

#endif // FUNCTIONALITIES_H
