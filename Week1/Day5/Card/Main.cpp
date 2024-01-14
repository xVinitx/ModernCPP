#include <iostream>
#include "Functionalities.h"

    int main() {
    Container data; //empty container
    CreateObjects(data);

    std::cout << "NthCustomer: " << NthCustomer(data, 2) << "\n";
    std::cout << "CVV of Given Customer: " << CvvOfGivenCustomerId(data, 111) << "\n";
    std::cout << "Expiry date of given CVV: " << ExpityDateofCVV(data, 101) << "\n";
    std::cout << "Debit Card for given Id: " << DebitCardForGivenId(data, 111) << "\n";

    try{
        Container ans = CustomersAgeAbov50(data);
        for (const Pointer& ptr : ans) {
            std::cout << *ptr << "\n";
        }
    } catch (std::runtime_error& ex) {
        std::cout << ex.what() << "\n";
    }
    
    return 0;
}
