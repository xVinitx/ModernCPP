#include <iostream>

#include "Functionalities.h"
#include "Vehicle.h"

int main() {
    const int size = 3;

    Vehicle* arr[3] = {nullptr};

    CreateObjects(arr, size);

    /*
        average price should be calculated for all instances

    */
    float ans = AveragePrice(arr, size);
    std::cout << "Average: " << ans;

    // Min price function

    int id = LowestPriceId(arr, size);
    std::cout << "\nLowest ID: " << id << std::endl;

    Display(arr, size);
}