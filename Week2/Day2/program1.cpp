#include <iostream>
#include <functional>
#include <vector>


/*
    perspective
                    std::reference_wrapper<int> ref = n1;
    a) compiler

    Instantiating via assignment a new object called ref. Data type
    of ref is std::reference_wrapper<T> Where T is equal to int

    b) programmer (user of readymade function)

    n1 ka referece gaya box mai, box ka naam ref
    n1's reference goes in box ref

    scenario 1: normally people take raw reference of a variable through =
    e.g int n1 = 10;
        int& ref = n1; // = assignment

        std::reference_wrapper<int> ref = n1;
        std::reference_wrapper<int> {n1};

    a reference wrapper is implicitly converted to a normal reference (raw reference)
*/


void Magic(std::reference_wrapper<int> ref) {
    std::cout << "Address of ref in Magic: " << &(ref.get()) << "\n";
    std::vector<std::reference_wrapper<int>> v1 {ref};
}

int main() {
    int n1 = 10;
    std::cout << "Address of n1 in Main : " << &n1 << "\n";
    Magic(n1);
}