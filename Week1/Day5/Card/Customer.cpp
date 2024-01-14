#include "Customer.h"

Customer::Customer(int id, std::string name, int age, CustomerType type, std::shared_ptr<DebitCard> card) 
    : _id(id), _name(name), _age(age), _type(type), _card(card) {

}

std::ostream &operator<<(std::ostream &os, const Customer &rhs) {
    os << "_id: " << rhs._id << "\n"
       << " _name: " << rhs._name << "\n"
       << " _age: " << rhs._age << "\n"
       << " _type: " << static_cast<int>(rhs._type) << "\n"
       << " _card: " << *rhs._card << "\n";
    return os;
}
