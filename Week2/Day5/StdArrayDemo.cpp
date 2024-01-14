#include <array>
#include <iostream>

int main() {
    // int arr1[3];
    std::array<int, 3> arr1;


    arr1[0] = 1;    
    arr1[1] = 2;
    arr1[2] = 3;

    for(int i = 0; i < 3; i++) {
        arr1[i] = (i+1) * 100;
    }   

    int count = 0;

    for(int val : arr1) {
        std::cout << val << "\n";
    }

    std::cout << arr1.size() << "\n";

    std::cout << "First Number: " << arr1.front() << "\n";

    std::cout << "Last number: " << arr1.back() << "\n";

    /*
        an array that contains 3 elements (3 rows)
        Each element of this array (each row) is itself
        AN ARRAY OF 2 integers
    */
    std::array<std::array<int, 2>, 3> arr2d{std::array<int, 2>{70, 30},
                                            std::array<int, 2>{40, 50},
                                            std::array<int, 2>{60, 70}};

    for(std::array<int,2> row : arr2d) {
        for(int element : row) {
            std::cout << element << "\n";
        }
    }

     std::cout << arr2d[1][1] << "\n";
}