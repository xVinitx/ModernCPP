#include <functional>
#include <iostream>

using FnType = std::function<int(int)>;

/*
    WHAT?
        Lambdas are callable like regular function
        (top-level functions/Global functions)
        Lambdas have no name i.e they are anonymous functions
    WHY?
        They help us to pass, recieve, store and utilize logic
        in the form of an object with proper type system functions

        They can be used for specifying short-term, one time or scope
        based logical process to be performed on some data

        Cpp Lambdas have a concept of capture clause which allows them
        to act like closures

        By using capture clause, a lambda function can access local
        variables of the enclosing function
*/

/*
    a) [n1] : capture n1 only by value
    b) [=] : capture and use all variables from surrounding function by value
    
    Options a and b will not allow modifying the copied data either!
    if you want to modify the copy variable, add mutable to the lambda function name.
    Youtube -> 

    [&n1] : capture n1 by lvalue reference
    [&] : capture all variables by reference
*/



auto n1 = 10;  // integer

auto lfn1 = [](int number) { return number * number; };

void operation(std::function<void()> f) {
    f();
}

int main() {
    int n1 = 10;
    // std::array<FnType, 1 > arr{lfn1};
    // std::cout << lfn1(n1) << "\n";

    // auto fn = []() {int n1 = 10; std::string _name = "Vinit";};

    // auto lf1 = [n1]() mutable { std::cout << n1 * n1;} // error

    auto fn2 = [n1]{int data = 10; std::cout << n1 * n1;};
    operation(fn2);
}