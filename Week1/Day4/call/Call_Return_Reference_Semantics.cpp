#include <iostream>

//if there is a data type to the left if &, it indicates reference of that data type
// reference - alrternate name (alias).//


int Magic(int& n1) {
    std::cout << "Address of data in Magic(): " << &n1 << "\n";
    // n1 = 1;
    int ans = n1 * 100;
    return ans;
}

int main() {
    // data variable initialized with value 20
    int data = 20;

    // address o data can be determined because data is lvalue
    std::cout << "Address of data in main: " << &data << "\n";

    // result stores the return "value" from Magic called with data passed by
    // value
    int result = Magic(data);
    std::cout << result << "\n";
}