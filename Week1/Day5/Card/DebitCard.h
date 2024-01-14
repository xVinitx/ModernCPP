#ifndef DEBITCARD_H
#define DEBITCARD_H

#include <iostream>

#include "DebitCardType.h"

class DebitCard {
   private:
    int _cvv{111};
    std::string _name_on_card{""};
    std::string _expiry{""};
    DebitCardType _type{DebitCardType::DOMESTIC};

   public:
    DebitCard() = delete;

    DebitCard(const DebitCard&) = delete;

    DebitCard& operator=(const DebitCard&) = delete;

    DebitCard(DebitCard&&) = delete;

    DebitCard& operator=(DebitCard&&) = delete;

    ~DebitCard() = default;

    int cvv() const { return _cvv; }

    std::string nameOnCard() const { return _name_on_card; }

    std::string expiry() const { return _expiry; }

    DebitCardType type() const { return _type; }

    DebitCard(int cvv, std::string name, std::string expiry,
              DebitCardType type);

    friend std::ostream &operator<<(std::ostream &os, const DebitCard &rhs);
};

#endif  // DEBITCARD_H
