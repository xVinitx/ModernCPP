/*
    Ceate a thread t1 that calculates square of all numbers
    in an array and stores them in a result container
*/

#include <array>
#include <iostream>
#include <thread>

int main() {
    std::array<int, 5> data{10, 20, 30, 40, 50};
    std::array<int, 5> result;
    /*
        create and instantiate t1
        std::thread(function_call, parameter);
    */
    std::thread t1(
        // function
        [&](std::array<int, 5>& data) {
            int k = 0;
            for (int val : data) {
                result[k++] = val * val;
            }
        },
        // arguments for function
        std::ref(data)
        );

    // wait for t1
    t1.join();

    /*
        display output
    */

    auto itr = data.begin();

    for (int val : result) {
        if (itr != data.end()) {
            std::cout << "Square of " << *itr << " is: " << val << "\n";
            itr++;
        }
    }
}