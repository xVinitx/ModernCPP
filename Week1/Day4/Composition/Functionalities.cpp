#include "Functionalities.h"

void CreateObjects(Container& data) {
    
    data.emplace_back(
        std::make_shared<Customer>(
            111, 
            "Vinit", 
            23, 
            CustomerType::ELITE,
            std::make_shared<DebitCard>(101, "Vinit Patil", "11/31", DebitCardType::INTERNATIONAL)
        )
    );

    data.emplace_back(
        std::make_shared<Customer>(
            101,
            "LordVinit",
            23,
            CustomerType::ELITE,
            std::make_shared<DebitCard>(121, "Lord Vinit", "12/31", DebitCardType::INTERNATIONAL)
        )
    );

}