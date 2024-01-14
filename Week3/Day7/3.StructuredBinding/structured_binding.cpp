#include <iostream>
#include <array>

int main() {
    std::array<int, 3> arr {101, 7000, 0};

    /*
        Aam Zindagi
    */

    int id = arr[0];
    int salary = arr[1];
    int gender = arr[2];

    /*
        Mentos Zindagi
    */

    auto [_id, _salary, _gender] = arr;

}