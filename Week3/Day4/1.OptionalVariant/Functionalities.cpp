#include "Functionalities.h"

void CreateObjects(Container& data) {
    data.emplace_back(
        std::make_shared<Car>(
            "C101",
            89000.0f,
            VehicleType::HATCHBACK
        )
    );
    data.emplace_back(
        std::make_shared<Car>(
            "C102",
            650000.0f,
            VehicleType::HATCHBACK
        )
    );
    data.emplace_back(
        std::make_shared<Car>(
            "C103",
            990000.0f,
            VehicleType::SUV
        )
    );

    data.emplace_back(
        std::make_shared<Bike>(
            "B101",
            89000.0f,
            VehicleType::SPORTS
        )
    );
    data.emplace_back(
        std::make_shared<Bike>(
            "B102",
            65000.0f,
            VehicleType::SPORTS
        )
    );
    data.emplace_back(
        std::make_shared<Bike>(
            "B103",
            99000.0f,
            VehicleType::SPORTS
        )
    );
}


float AveragePrice(const Container& data) {
    if(data.empty()) {
        throw std::runtime_error("Empty Data");
    }
    float total = 0.0f;
    for(const VType& v : data) {
        std::visit(
            [&] (auto && val) { 
                total = total + val->price();
            },
            v
        );
    }

    return total/data.size();
}

VType InstanceWithMinimumPrice(const Container& data) {
    if(data.empty()) {
        throw std::runtime_error("Data is empty,");
    }
    
    float minprice = 0.0f;
    auto itr = data.begin();

    VType v2;

    std::visit([&](auto&& ptr) { minprice = ptr->price(); v2 = ptr;}, *itr);
    
    for (const VType& v : data) {
        std::visit(
            [&](auto&& val) {
                if (minprice > val->price()) {
                    minprice = val->price();
                    v2 = val;
                }
            },
            v);
    }

    return v2;
}

bool IfIDExists(const Container& data, std::string id) { 
    if(data.empty()) {
        throw std::runtime_error("Data is empty.");
    }

    bool flag = false;
    for(const VType v : data) {
        std::visit(
            [&](auto&& val){
                if(val->id() == id) {
                    flag = true;
                }
            },
            v
        );
    }

    return flag;
}


std::optional<Container> InstancesMatchingType(const Container& data,
                                               VehicleType type) {
    if (data.empty()) {
        throw std::runtime_error("Empty Data.");
    }

    Container result;

    for (const VType& v : data) {
        std::visit(
            [&](auto&& val) {
                if (val->type() == type) {
                    result.emplace_back(val);
                }
            },
        v);
    }

    /*
        - if result is empty even after for loop, it means no instance has a
       matching type
        - Compiler should be notified that result has no valid value. this is
       why we send nullopt

    */

    if (result.empty()) {
        return std::nullopt;
    }

    return result;
}   
