#include "Functionalities.h"
#include <iostream>
#include <thread>

int main() {
    Container data;
    CreateObjects(data);

    std::array<std::thread, 6> arr;

    try{
        std::cout<<"AverageProductPrice: "<<std::endl;
        arr[0] = std::thread (AverageProductPrice, std::ref(data), ProductType::FOOD);
    } catch (std::runtime_error& ex) {
        std::cout << ex.what() << "\n";
    }

    try {
        std::cout<<"TaxOfProductWithMaxPrice: "<<std::endl;
        arr[1] = std::thread(TaxOfProductWithMaxPrice, std::ref(data));
    } catch (std::runtime_error& ex) {
        std::cout << ex.what() << "\n";
    }

    try {
        std::cout << "Last N instances." << "\n";
        arr[2] = std::thread(LastNInstancesOfProduct, std::ref(data), 2);
    } catch (std::runtime_error& ex) {
        std::cout << ex.what() << "\n";
    }

    try {
         std::cout << "UniqueBrands" << "\n";
        arr[3] = std::thread (UniqueProductBrands, std::ref(data));
    } catch (std::runtime_error& ex) {
        std::cout << ex.what() << "\n";
    }

    try {
        std::cout << "Count" << "\n";
        arr[4] = std::thread (CountOfFoodAndDomesticProduct, std::ref(data));
    } catch (std::runtime_error& ex) {
        std::cout << ex.what() << "\n";
    }

    try {
        std::cout << "Brand Name." << "\n";
        arr[5] = std::thread (ProductWithGivenBrandName, std::ref(data), "Asus");
    } catch (std::runtime_error& ex) {
        std::cout << ex.what() << "\n";
    }

    for(std::thread& thr : arr) {
        if(thr.joinable()) {
            thr.join();
        }
    }

}