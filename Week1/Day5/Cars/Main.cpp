#include "Functionalities.h"

int main() {

    Container data;
    CreateObjects(data);

    std::cout << "Horsepower of Car with Id: " << EngineHorsepowerOFCar(data, "111") << "\n";
    std::cout << "Average Horsepower of Cars: " << AverageHorsePower(data) << "\n";
    std::cout << "Lowest Price: " << CarWithLowestPrice(data) << "\n";
    std::cout << "Combined Price: " << CombinedPriceOfTwoCars(*data[0], *data[1]) << "\n";

    auto ans = EngineTorqueOver80(data);
    for (auto& dis : ans) {
        std::cout << *dis << "\n";
    }

    auto ans1 = MatchCarType(data, CarType::SEDAN);
    for (auto& dis : ans1) {
        std::cout << *dis << "\n";
    }


    return 0;

}