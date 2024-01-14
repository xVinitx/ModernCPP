#include "Product.h"

Product::Product(std::string productId, ProductType productType, float productPrice,
                 std::string productBrand, ProductOrigin productOrigin, float productTaxAmmount) 
                : _productId(productId), 
                _productType(productType), 
                _productPrice(productPrice), 
                _productBrand(productBrand),
                _productOrigin(productOrigin),
                _productTaxAmmount(productTaxAmmount) 
                {
                    
                }



std::ostream &operator<<(std::ostream &os, const Product &rhs) {
    os << "_productId: " << rhs._productId
       << " _productType: " << static_cast<int>( rhs._productType)
       << " _productPrice: " << rhs._productPrice
       << " _productBrand: " << rhs._productBrand
       << " _productOrigin: " << static_cast<int>(rhs._productOrigin)
       << " _productTaxAmmount: " << rhs._productTaxAmmount;
    return os;
}

