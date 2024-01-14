#include "Engine.h"

Engine::Engine(std::string engineNumber, int engineHorsepower, int engineTorque,
  EngineType engineType)
  : _engineNumber(engineNumber),
  _engineHorsepower(engineHorsepower),
  _enginetorque(engineTorque),
  _engineType(engineType) {}

std::ostream& operator<<(std::ostream& os, const Engine& rhs) {
  os << "\n _engineNumber:      " << rhs._engineNumber << "\n"
    << " _engineHorsepower:  " << rhs._engineHorsepower << "\n"
    << " _enginetorque:      " << rhs._enginetorque << "\n"
    << " _engineType:        " << static_cast<int>(rhs._engineType) << "\n";
  return os;
}
