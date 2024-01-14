#include "Functionalities.h"

void CreateObjects(Container& data) noexcept {
    
    data.emplace_back(
        std::make_shared<Customer>(
            111, 
            "Vinit", 
            58, 
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

float Average(Container& data) {
    if (data.empty()) {
        throw std::runtime_error("empty data");
    }

    float total;

    for(Pointer& ptr : data) {
                        //smart pointer used as regular pointer
        total = total + ptr->age();
    }

    return total / data.size();
}

Pointer NthCustomer(Container& data, int N) {
    if(data.empty()) {
        throw std::runtime_error("Data is empty.");
    }

    if(N > data.size() || N < 1) {
        throw std::runtime_error("N is beyond available items.");
    }


    auto itr = data.begin();

    while(N > 1) {
        itr++;
        N--;
    } 

    return *itr;

    // return data[N-1];
}

int AgeOfGivenCustomerId(Container &data, int id) { 
    if(data.empty()) {
        throw std::runtime_error("Data is empty.");
    }

    for(Pointer& ptr : data) {
        if(ptr->id() == id) {
            return ptr->age();
        }
    }    

    throw std::runtime_error("ID NOT FOUND");

}

int CvvOfGivenCustomerId(const Container& data, const int id) {
    if(data.empty()) {
        throw std::runtime_error("Data is empty.");
    }

    for (const Pointer& ptr : data) {
        if (ptr->id() == id) {
            return ptr->card()->cvv();
        }
    }

    throw std::runtime_error("ID NOT FOUND");
}

std::string ExpityDateofCVV(const Container& data, const int cvv) {
    if (data.empty()) {
        throw std::runtime_error("Data is empty.");
    }

    for (const Pointer& ptr : data) {
        if (ptr->card()->cvv() == cvv) {
            return ptr->card()->expiry();
        }
    }

    throw std::runtime_error("CVV NOT FOUND");
}

Container CustomersAgeAbov50(const Container& data) {
    if (data.empty()) {
        throw std::runtime_error("Data is empty.");
    }
    Container result;
    for (const Pointer& ptr : data) {
        if (ptr->age() > 50 ) {
            // result.emplace_back(ptr);
        }
    }

    if(result.empty()) {
        throw std::runtime_error("No customer above age 50.");
    }
    
    return result;
}


std::shared_ptr<DebitCard> DebitCardForGivenId(const Container& data, int id) {
    if (data.empty()) {
        throw std::runtime_error("Data is empty.");
    }

    for (const Pointer& ptr : data) {
        if (ptr->id() == id) {
            return ptr->card();
        }
    }

    throw std::runtime_error("Id not found.");
}
