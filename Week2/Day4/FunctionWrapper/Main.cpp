#include "Functionalities.h"

using namespace std::placeholders;

int main() {
    Container data;
    auto fn = std::bind(SalaryGivenID, _1, 101);
    fn(data);
}