#include "Functionalities.h"

int main() {
    Container data;
    CreateObjects(data);

    std::cout << AveragePrice(data) << "\n";

    // std::boolalpha gives TRUE or FALSE
    std::cout << std::boolalpha << IfIDExists(data, "C101") << "\n"; 
    
    VType answer = InstanceWithMinimumPrice(data);
    std::visit(
                [&](auto&& ptr){
                    std::cout << *ptr<< "\n";
                },
                answer
            );

    auto ans = InstancesMatchingType(data, VehicleType::SEDAN);

    // ans.value(); // nahi likhna tha
    if(ans.has_value()) {
        for(auto &ptr : ans.value()) {
            std::visit(
                [&](auto &&val){
                    std::cout << *val << "\n";
                },
                ptr
            );
        }
    }
    else {
        std::cout << "Nullopt" << "\n";
    }
}