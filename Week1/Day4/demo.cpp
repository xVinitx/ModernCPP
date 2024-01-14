#include <iostream>
#include <memory>

#include "Customer.h"
#include "CustomerType.h"
#include "DebitCard.h"
#include "DebitCardType.h"

std::shared_ptr<Customer> dummy() {
    // auto keyword is used to guess the datatype of the variable based on the
    // initialization value.
    std::shared_ptr<Customer> ptr = std::make_shared<Customer>(
        101, 
        "Vinit", 
        23, 
        CustomerType::ELITE,
        std::make_shared<DebitCard>(101, "Vinit Patil", "11/28", DebitCardType::INTERNATIONAL)
    );

    return ptr;
}

int main() {
    // dummy function returns shared ptr TO customer.
    std::shared_ptr<Customer> ans = dummy();
}