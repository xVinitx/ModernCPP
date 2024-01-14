#include "Functionalities.h"

void CreateObjects(CarContainer& carData, EngineContainer& engineData) {
    engineData[0] = std::make_shared<Engine>(
        101, 
        EngineType::DIESEL
    );

    carData[0] = std::make_shared<Car>(
        101, 
        "Nexon", 
        1300000.0f,
        engineData[0]
    );
}

