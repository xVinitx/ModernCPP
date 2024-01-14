#include <iostream>


/*
    
    &                               (just name)
    
    address         Name            Content
    0x100H          n1              10
    0x111H          ptr             0x100H
    0x891H          sptr            0x111H

*/


int main() {
    int n1 = 10;

    int* ptr = &n1;

    //sptr is a pointer to a pointer
    int** sptr = &ptr;

    std::cout << "Content in n1 is: " << n1 << std::endl;
    std::cout << "Address of n1 is: " << &n1 << std::endl;

    std::cout << "Content in ptr is: " << ptr << std::endl;
    std::cout << "Address of ptr is: " << &ptr << std::endl;

    std::cout << "Content in sptr is: " << sptr << std::endl;
    std::cout << "Address of sptr is: " << &sptr << std::endl;

    std::cout << *sptr << std::endl;
    std::cout << **sptr << std::endl;
    
}