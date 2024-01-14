#include <iostream>
#include <memory>

int main() {
    int* ptr = (int* ) malloc(16);
    std::shared_ptr<int[4]> ptr();
}