#ifndef ENGINE_H
#define ENGINE_H

#include <EngineType.h>
#include <ostream>

class Engine
{
private:
    int _horsepower;
    EngineType _engineType;

public:
    Engine(int horsepower, EngineType engineType);
    ~Engine() = default;

    int horsepower() const { return _horsepower; }

    EngineType engineType() const { return _engineType; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
}; 

#endif // ENGINE_H
