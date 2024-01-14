#include <functional>
#include <memory>

#include "Product.h"

using Pointer = std::shared_ptr<Product>;
using Container = std::vector<Pointer>;



void CreateObjects(Container& data);

void operations(std::function<void(Container&, ProductType)> logic, 
                    Container& data, ProductType ProductType);

extern std::function<void(Container&, ProductType)> AverageProductPrice;

using func = std::function<void(Container&)>;
void operations(func logic, Container& data);
extern func TaxOfProductWithMaxPrice;

void operations(std::function<void(Container&, int)> logic, Container& data, int N);
extern std::function<void(Container&, int)> LastNInstancesOfProduct;

extern func UniqueProductBrands;

extern func CountOfFoodAndDomesticProduct;

void operations(std::function<void(Container&, std::string)> logic, Container& data, std::string name);
extern std::function<void(Container&, std::string)> ProductWithGivenBrandName;