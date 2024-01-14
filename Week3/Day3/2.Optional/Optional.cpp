#include <iostream>
#include <vector>
#include <optional>

void TakeInput(std::vector<int>& data, int N) {
    int val = -1;
    
    for(int i = 0; i < data.size(); i++) {
        std::cin >> val;
        data[i] = val;
    }

    // while (N > 0) {
    //     std::cin >> val;
    //     data[i] = val;
    //     i++;
    //     N--;
    // }
}

/*
    identify even numbers from data.
    store all of them in result 
    return result

    scenario 1: there is at least 1 even number in data.
                you identify the number/s. store in result

    scenario 2: data is empty. handle by raising exception

    scenario 3: data is not empty. However, all numbers are ODD
*/

std::optional< std::vector<int> > ReturnEvenNumbers(std::vector<int>& data) {
    if(data.empty()) {
        throw std::runtime_error("Error as data is empty");
    }

    std::vector<int> result;

    for(int v : data) {
        if(v % 2 == 0) {
            result.emplace_back(v);
        }
    }

    if(result.empty()) {
        return std::nullopt; // nullopt is a symbol to indicate no value
    }
    
    return result;
}


int main() {
    int N = 0;
    std::cin >> N;

    std::vector<int> v1(N); // space for N integers is now reserved on the heap
    // std::vector<int> v1;
    std::vector<int> data;
    // v1.reserve(N);

    TakeInput(v1, N);

    std::optional <std::vector<int>> even_numbers = ReturnEvenNumbers(v1);

    /*
        has_value returns false if optional wrapper contains nullopt
        has_value returns true if a valid value is found in optional
        
    */

    if(even_numbers.has_value()) {

        /*
            we only come inside if when has_value return true
            i.e container of even numbers is found in optional
        */

        std::cout << even_numbers.value().size() << "\n";
    } 
    else {
        std::cout <<"No Even numbers \n";
    }
}