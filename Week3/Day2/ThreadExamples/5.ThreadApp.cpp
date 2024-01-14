/*
    Create an array of 5 threads that calculate the square
    of ONE NUMBER FROM AN ARRAY OF 5 integers. Store answers in a result container
*/

#include <array>
#include <thread>
#include <iostream>
#include <functional>

void InstantiateThread(
    std::array<std::thread, 5>& threadArr, 
    std::function<void(int, int)> f1,
    std::array<int, 5> data
) {
    auto itr = data.begin();

    for (int i = 0; i < 5; i++) {
        threadArr[i] = std::thread(f1, *itr++, i);
    }
}

void JoinThreads(std::array<std::thread, 5>& threadArr) {
    for (std::thread& t : threadArr) {
        if (t.joinable()) {
            t.join();
        }
    }
}

void DisplayResult(std::array<int, 5>& result, std::array<int, 5>& data) {
    // for each for display

    auto itr = data.begin();

    for (int val : result) {
        if (itr != data.end()) {
            std::cout << "Square of " << *itr << " is: " << val << "\n";
            itr++;
        }
    }

    std::cout << std::endl;
}

void StartApp() {
    std::array<int, 5> data{10, 20, 30, 40, 50};
    std::array<int, 5> result;

    int k = 0;

    auto f1 = [&](int number, int idx) { result[idx] = number * number; };

    std::array<std::thread, 5> threadArr;
    InstantiateThread(threadArr, f1, data);
    JoinThreads(threadArr);
    DisplayResult(result, data);
}


int main() {
    StartApp();
}
