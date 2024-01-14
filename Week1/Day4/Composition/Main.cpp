#include <iostream>
#include "Functionalities.h"


int main() {
    Container data; //empty container
    CreateObjects(data);

    for(const auto &dis : data) {
        std::cout << *dis << "\n";
    }
    return 0;
}