#include "Car.h"


std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_id: " << rhs._id
       << " _model: " << rhs._model
       << " _float: " << rhs._price
       << " _engine: " << rhs._engine.get();
    return os;
}

