#include "Functionalities.h"
#include <set>

void CreateObjects(Container& data) {
    data.emplace_back(
        std::make_shared<Product>(
            "101",
            ProductType::FOOD,
            100.0f,
            "Apple",
            ProductOrigin::DOMESTIC,
            (0.05 * 100.0f)
        )
    );
    data.emplace_back(
        std::make_shared<Product>(
            "102",
            ProductType::APPLIANCE,
            1000.0f,
            "Asus",
            ProductOrigin::IMPORTED,
            (0.05 * 1000.0f)
        )
    );
    data.emplace_back(
        std::make_shared<Product>(
            "103",
            ProductType::PERFUME,
            10.0f,
            "Titan",
            ProductOrigin::DOMESTIC,
            (0.05 * 10.0f)
        )
    );
}

std::function<void(Container&, ProductType)> AverageProductPrice = 
                    [] (Container& data, ProductType productType) {
    if(data.empty()) {
        throw std::runtime_error("Data is empty.");
    }

    float total = 0.0f;
    int count = 0;
    for(Pointer& ptr : data) {
        if(ptr->productType() == productType) {
            total += ptr->productPrice();
            count++;
        }
    }

    std::cout <<  total/count << "\n";

};

void operations(func logic, Container& data) {
    logic(data);
}

func TaxOfProductWithMaxPrice = [](Container& data) {
    if (data.empty()) {
        throw std::runtime_error("Data is empty.");
    }
    auto max = data.front();
    for(Pointer& ptr : data) {
        if(ptr->productPrice() > max->productPrice()) {
            max = ptr;
        }
    }

    std::cout << max->productTaxAmmount() << "\n";
};


std::function<void(Container&, int)> LastNInstancesOfProduct = [] (Container& data, int N) {

    if (data.empty()) {
        throw std::runtime_error("Data is empty.");
    }

    Container result;

    auto itr = data.end();

    while (N > 0) {
        itr--;
        N--;
        result.emplace_back(*itr);
    }

    if (result.empty()) {
        throw std::runtime_error("Result is empty.");
    }

    for (const Pointer& ptr : result) {
        std::cout << *ptr << "\n";
    }
    
};

std::function<void(Container&)> UniqueProductBrands = [](Container& data) {
    if (data.empty()) {
        throw std::runtime_error("Data is empty.");
    }
    
    using Set = std::set<Pointer>;
    Set s1;

    for(Pointer& ptr : data) {
        s1.emplace(ptr);
    }

    for (const Pointer& ptr : s1) {
        std::cout << *ptr << "\n";
    }

};

func CountOfFoodAndDomesticProduct = [](Container& data) {
    if (data.empty()) {
        throw std::runtime_error("Data is empty.");
    }
    int count1 = 0;
    int count2 = 0;
    std::array<int, 2> arr;

    for(Pointer& ptr : data) {
        if(ptr->productType() == ProductType::FOOD) {
            count1++;
        }
        if(ptr->productOrigin() == ProductOrigin::DOMESTIC) {
            count2++;
        }
    }
    arr[0] = count1;
    arr[1] = count2;
    for(int a : arr) {
        std::cout << a << "\n";
    }
};


std::function<void(Container&, std::string)> ProductWithGivenBrandName =
    [](Container& data, std::string name) {
        if (data.empty()) {
            throw std::runtime_error("Data is empty.");
        }

        Container addresses;

        for(Pointer& ptr : data) {
            if(ptr->brand() == name) {
                addresses.emplace_back(ptr);
            }
        }

        for (const Pointer& ptr : addresses) {
            std::cout << *ptr << "\n";
        }

    };