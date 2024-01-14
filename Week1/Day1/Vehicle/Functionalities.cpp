#include "Functionalities.h"

void CreateObjects(Vehicle** arr, const int size) {
    // arr[0] = new Vehicle(101, "Maruti Dzire", 850000.0f,
    // VehicleType::PERSONAL);

    // int id = 0;
    // std::string name = "";
    // float price = 0.0;
    // VehicleType type = VehicleType::PERSONAL;
    // int choice = -1;

    for (int i = 0; i < size; i++) {
        int id = 0;
        std::string name = "";
        float price = 0.0;
        VehicleType type = VehicleType::PERSONAL;
        int choice = -1;

        std::cin >> id;
        std::cin >> name;
        std::cin >> price;
        std::cin >> choice;
        if (choice == 0) {
            type = VehicleType::PERSONAL;
        }

        else if (choice == 1) {
            type = VehicleType::SECURITY;
        }

        else if (choice == 2) {
            type = VehicleType::TRANSPORT;
        }

        else {
            type = VehicleType::PERSONAL;
        }

        arr[i] = new Vehicle(id, name, price, type);
    }
}

float AveragePrice(Vehicle** arr, const int size) {
    float total = 0.0f;

    for (int i = 0; i < size; i++) {
        total += arr[i]->price();
    }

    return total / size;
}

int LowestPriceId(Vehicle** arr, const int size) {
    // first location is for minimum price
    int ans = arr[0]->id();
    int _min_price = arr[0]->price();

    for (int i = 0; i < size; i++) {
        float _current_price = arr[i]->price();

        if (_current_price < _min_price) {
            _min_price = _current_price;
            ans = arr[i]->id();
            VehicleType a = arr[i]->type();
        }
    }

    return ans;
}

void Display(Vehicle** arr, const int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "Id: " << arr[i]->id() << std::endl;
        std::cout << "Model Name: " << arr[i]->modelName() << std::endl;
        std::cout << "Price: " << arr[i]->price() << std::endl;
        // std::cout << "Type: " << arr[i]->type() << std::endl;
        VehicleType vt = arr[i]->type();

        switch (vt) {
            case VehicleType::PERSONAL:
                std::cout << "Personal Vehicle." << std::endl;
                break;
            case VehicleType::SECURITY:
                std::cout << "Security Vehicle." << std::endl;
                break;
            case VehicleType::TRANSPORT:
                std::cout << "Transport Vehicle." << std::endl;
                break;
            default:
                std::cout << "Personal Vehicle." << std::endl;
        }
    }
}
