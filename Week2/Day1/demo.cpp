#include <iostream>
#include <functional>


void operation(std::function <void(int)> logic, int data) { 
    logic(data); 
}


void times100(int number) { 
    std::cout << number * 100 << "\n"; 
}

void percent10(int number) { 
    std::cout << (int)number * 0.1f << "\n"; 
}

int main() {
    // a function pointer (which points to a function
    // TYPE OF PTR is signature of function

    operation(percent10, 100);
    
    operation([](int number) { std::cout << number * number << "\n"; }, 5);
    operation([](int number) { std::cout << number * number * number << "\n"; }, 5);

    operation([](int number) { std::cout << number * 100; }, 10);

}