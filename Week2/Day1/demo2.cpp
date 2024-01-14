/*
    a container of 3 functions
    run a loop over the container to execute the functions

    |       |       |
    f1      f2      f3
    |       |       |
    o1      o2      o3


*/

#include <functional>
#include <iostream>
#include <vector>

using FnType = std::function<void(int)>;
using FnContainer = std::vector<FnType>;

void MakeLambdaFunctions(FnContainer& functions) {
    functions.emplace_back(
        [](int number) { 
            std::cout << number * number << "\n"; 
        }
    );

    functions.emplace_back(
        [](int number) { 
            std::cout << number * number * number << "\n"; 
        }
    );
    functions.emplace_back(
        [](int number) { 
            std::cout << number * 100 << "\n"; 
        }
    );
}

/*
    run a for each loop on the function container
    execute each function with given data
*/

void ApplyLogicOnData(FnContainer& functions, int data) {
    for (FnType& fn : functions) {
        fn(data);
    }
}


int main() {
    FnContainer functions;
    MakeLambdaFunctions(functions);
    ApplyLogicOnData(functions, 5);
}
