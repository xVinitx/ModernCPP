#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "DebitCard.h"
#include <memory>
#include "CustomerType.h"


class Customer {
   private:
    int _id{101};
    std::string _name{""};
    int _age{18};
    CustomerType _type{CustomerType::REGULAR};
    std::shared_ptr<DebitCard> _card;
 
   public:
    Customer() = delete;

    Customer(const Customer&) = delete;

    Customer& operator=(const Customer&) = delete;

    Customer(Customer&&) = delete;

    Customer& operator=(Customer&&) = delete;

    ~Customer() = default;

    Customer(int id, std::string name, int age, CustomerType type, std::shared_ptr<DebitCard> card);

    int id() const { return _id; }

    std::string name() const { return _name; }

    int age() const { return _age; }

    CustomerType type() const { return _type; }

    std::shared_ptr<DebitCard> card() const { return _card; }

    friend std::ostream &operator<<(std::ostream &os, const Customer &rhs);

    
};

#endif  // CUSTOMER_H
