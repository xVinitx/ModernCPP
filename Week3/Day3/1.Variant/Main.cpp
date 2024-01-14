#include "Employee.h"
#include "BusinessOwner.h"
#include <variant>
#include <memory>
#include "Functionalities.h"

int main() {
    std::variant<Employee, BusinessOwner> v1;
    v1 = Employee();
    
    /*
        visit needs atleast 2 parameters
        first: Lambda function that explains what to do with item inside the variant
        second (and subsequent parameters): objects of variant class. (object/s on which 
        visit lambda has to be applied)
    */
    std::visit(
        [] (auto&& val) {val.PayTax();},
        v1
    );

    v1 = BusinessOwner();
    std::visit(
        [] (auto&& val) {val.PayTax();},
        v1
    );

    EmpPointer e1 = std::make_shared<Employee>();

    VType v2;
    v2 = e1; // storing e1 inside the variant. This should be stored in slot 1

    std::visit(
        [] (auto&& val) {val->PayTax(); },
        v2
    );
    // std::visit(
    //     [] (auto&& val) { std::cout << val->PayTax(); },
    //     v2
    // );
    std::get<BusinessOwner>(v1).PayTax();
}