#include "Functionalities.h"
#include <thread>
#include <iostream>

int main() {
    Container data;

    std::array< std::thread, 3 > arr;

    arr[0] = std::thread (CreateObjects, std::ref(data));

    arr[0].join();
    
    arr[1] = std::thread (CallParenOperator, std::ref(data));

    arr[2] = std::thread (CalculateTaxPayable, std::ref(data));

    for(std::thread& th : arr) {
        if(th.joinable()) {
            th.join();
        }
    }

    // CreateObjects(data);
    // CalculateTaxPayable(data);
    // CallParenOperator(data);
}