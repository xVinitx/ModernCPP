#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include "ProductType.h"
#include "ProductOrigin.h"

class Product
{
private:
    std::string _productId;
    ProductType _productType;
    float _productPrice;
    std::string _productBrand;
    ProductOrigin _productOrigin;
    float _productTaxAmmount;

public:
    Product() = default;
    Product(const Product&) = delete;
    Product& operator=(const Product&) = delete;
    Product(Product&&) = delete;
    Product& operator=(Product&&) = delete;
    ~Product() = default;


    Product(std::string productId, ProductType productType, float productPrice, 
            std::string productBrand, ProductOrigin productOrigin, float productTaxAmmount);

    std::string productId() const { return _productId; }

    ProductType productType() const { return _productType; }

    float productPrice() const { return _productPrice; }

    std::string brand() const { return _productBrand; }

    ProductOrigin productOrigin() const { return _productOrigin; }

    float productTaxAmmount() const { return 0.05 * _productTaxAmmount; }

    friend std::ostream &operator<<(std::ostream &os, const Product &rhs);

};

#endif // PRODUCT_H
