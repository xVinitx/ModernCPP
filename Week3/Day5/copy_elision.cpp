#include <iostream>

class MyClass {
private:
    int _id;
public:
    MyClass() = default;
    MyClass(MyClass &&) = default;
    MyClass(const MyClass &) { std::cout << "Copy constructor called.\n"; } // nahi karna tha. Side effect.
    MyClass &operator=(MyClass &&) = delete;
    MyClass &operator=(const MyClass &) = delete;
    ~MyClass() = default;

    MyClass (int id) : _id(id) {};
};

// step 4 : signature is matched and Magic is invoked
MyClass Magic(MyClass& obj) {
    // step 5 : temp object is instantiated by "copy constructor"
    MyClass temp(obj);

    // step 6 : address of temp is printed
    std::cout << "Address of temp is: " << &temp << "\n";

    // step 7 : temp is returned by value
    return temp;
}

int main() {
    // step 1 : Obj gets instantiated
    MyClass obj(100);
    // step 2 : address is printed (obj is in the stack of main function)
    std::cout << "Address of obj is: " << &obj << "\n";

    // step 3 : Call Magic function. Whatever is returned from Magic will be saved
    // in return_obj variable

    /*
        return_obj is a variable which is "assigned" the return value of Magic
        return_obj is assigned an rvalue
    */
    MyClass return_obj = Magic(obj);
    
    // final step
    std::cout << "Address of return_obj: " << &return_obj << "\n";
}