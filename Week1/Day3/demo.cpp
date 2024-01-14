#include <iostream>
#include <list>
#include <vector>
#include <memory>


/*


*/

struct Employee{
    int id;
    std::string name;
};

class Car {
private:
    int id;
    std::string name;
public:
    Car(/* args */) {}
    ~Car() {}
};

int main() {
    int n1 {10};
    int* ptr {&n1};
    struct Employee {101, "Vinit"}; 
    Car c1{};
    Car c2(101, "Dzire");
    int arr[3] {10, 20, 30};

    std::list <int> data {1, 2, 3};

    std::vector <int> values {1, 2, 3};

    std::shared_ptr<int> ptr2 {ptr};
}