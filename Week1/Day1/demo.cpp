#include <iostream>

enum class Rank {
    FIRST,
    SECOND,
    THIRD
};

enum class Gear {
    FIRST,
    SECOND,
    THIRD
};

void magic(int data) {

}

int main() {
    enum Rank r1 = Rank::FIRST;

    enum Gear g1 = Gear::FIRST;

    /*
    if(r1 == g1) { // not alowed to compare two diferent enums
        std::cout << "OOPS!!!\n";
    }
    */

    // magic(r1);   // enum not defaulted to int 
}