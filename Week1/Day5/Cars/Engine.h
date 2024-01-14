#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>

#include "EngineType.h"

class Engine {
private:
    std::string _engineNumber{ "1101" };
    int _engineHorsepower{ 500 };
    int _enginetorque{ 91 };
    enum EngineType _engineType { EngineType::HYBRID };

public:
    Engine() = default;
    ~Engine() = default;

    Engine(std::string engineNumber, int engineHorsepower, int engineTorque, EngineType engineType);

    std::string engineNumber() const { return _engineNumber; }

    int engineHorsepower() const { return _engineHorsepower; }

    int enginetorque() const { return _enginetorque; }

    enum EngineType engineType() const { return _engineType; }

    friend std::ostream& operator<<(std::ostream& os, const Engine& rhs);

};

#endif  // ENGINE_H
