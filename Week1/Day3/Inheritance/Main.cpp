#include <iostream>
#include "Functionalities.h"

int main() {
    Container data;
    CreateObjects(data);
    std::cout << AveragePrice(data) << "\n";

    Display(data);

    return 0;    
}