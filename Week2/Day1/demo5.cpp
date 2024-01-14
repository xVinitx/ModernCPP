#include <functional>
#include <iostream>
#include <vector>

#include "State.h"

using FnType = std::function<void(int)>;
using FnContainer = std::vector<FnType>;
using DataContainer = std::vector<int>;

void MakeLambdaFunctions(FnContainer& functions) {
    functions.emplace_back(
        [](int number) { std::cout << number * number << "\n"; });

    functions.emplace_back(
        [](int number) { std::cout << number * number * number << "\n"; });

    functions.emplace_back(
        [](int number) { std::cout << number * 100 << "\n"; });
}

void TakeData(DataContainer& data) {
    for (int& dt : data) {
        data.emplace_back(10);
        data.emplace_back(20);
        data.emplace_back(30);
    }
}

void ApplyLogicOnData(const FnContainer& functions, const DataContainer& data) {
    for (int i = 0; i < 3; i++) {
        for (const FnType& fn : functions) {
            for (const int n : data) {
                fn(n);
            }
        }
    }
}

int main() {
    FnContainer functions;
    MakeLambdaFunctions(functions);
    DataContainer data;
    ApplyLogicOnData(functions, data);
}
