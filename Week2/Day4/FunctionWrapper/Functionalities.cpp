#include "Functionalities.h"




std::function<float(Container&)> AverageSalary = [] (Container& data) {
    float total = 0.0f;
    int count = 0;
    for(Pointer& ptr : data) {
        total += ptr->salary();
        ++count;
    }
    return total/count;
};