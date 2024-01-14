#include <functional>
#include <iostream>
#include <vector>

using FnType = std::function<void(int)>;
using FnContainer = std::vector<FnType>;
using DataContainer = std::vector<int>;

void MakeLambdaFunctions(FnContainer& functions) {
    functions.emplace_back(
        [](int number) { std::cout << number * number << "\n"; }
    );

    functions.emplace_back(
        [](int number) { std::cout << number * number * number << "\n"; }
    );

    functions.emplace_back(
        [](int number) { std::cout << number * 100 << "\n"; }
    );
}

void ApplyLogicOnData(const FnContainer& functions, const DataContainer& data) {


    for (const FnType& fn : functions) {
        for(const int n : data) {
            fn(n);
        }
    }
}

int main() {
    FnContainer functions;
    MakeLambdaFunctions(functions);
    DataContainer data{10, 20, 30};
    ApplyLogicOnData(functions, data);
}
