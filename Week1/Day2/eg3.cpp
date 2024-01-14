#include <iostream>
#include <memory>

#include "Vehicle.h"
#include "VehicleType.h"

int main() {
    std::shared_ptr<Vehicle> ptr = std::make_shared<Vehicle>(
        101, 
        "city", 
        1400000.0f, 
        VehicleType::PERSONAL
    );
}

/*
    RAII - Resource Aquisition is Initialization 

    1) When we acquire resource, something is initialized
    
    2) If I want to acquire resource then I must acquire it 
    while initializing "something"

    File f1 = open()
*/