#include "Functionalities.h"
#include "Employee.h"
#include <memory>
#include <vector>
#include "DataModeller.h"
#include <mutex>

std::mutex mt;


void CreateObjects(Container& data) {
    data.emplace_back( 
        std::make_unique<DataModeller> (
        // instance
            std::make_unique<Employee>(
                "Vinit",
                EmployeeType::REGULAR,
                780000.0f
                ),
            // vector of floats
            std::vector<float> {19.21f, 145.31f, 204.12f}
        )
    );

    data.emplace_back( 
        std::make_unique<DataModeller> (
        // instance
            std::make_unique<BusinessOwner>(
                1000000.0f,
                2000000.0f,
                "The Vinit Corporation",
                BusinessType::MNC
                ),
            // vector of floats
            std::vector<float> {19.21f, 145.31f, 204.12f}
        )
    );

}

/*
    This function will accept a Container of DataModeller pointer

    FOR EACH POINTER, perform the following

    a. capture the instance reference
    b. Use holds_alternative to verify which type of pointer is present in the _instance
    c. if pointer is of type BusinessOwner 
            i. Use std::get to fetch BusinessOwnerPointer (This will be safe because if has been checked)
            ii. use the fetched pointer to fetch type of employee
            iii. if type is REGULAR tax is 10% else it should be 20% of salary
*/

void CalculateTaxPayable(const Container& data) {
    if (data.empty()) {
        throw std::runtime_error("EMPTY!");
    }

    for (const dataPointer& ptr : data) {
        const VType& val = ptr->instance();

        if (std::holds_alternative<BusinessPointer>(val)) {
                const BusinessPointer& p = std::get<BusinessPointer>(val);
                std::cout << "Business Tax: " << 0.1 * (p->revenue() - p->expense()) << "\n";
            }
        else {
            // const EmpPointer& p = std::get<EmpPointer>(val);

            if (const EmpPointer& p = std::get<EmpPointer>(val);
                p->type() == EmployeeType::REGULAR) {
                std::lock_guard<std::mutex> lk(mt);
                std::cout << "Tax is 10%: "<< 0.1 * p->salary() << "\n";
            } else {
                std::lock_guard<std::mutex> lk(mt);
                std::cout << "Tax is 20%: " << 0.2 * p->salary() << "\n ";
            }
        }
    }
}

void CallParenOperator(const Container& data) {
    if(data.empty()) {
        throw std::runtime_error("EMPTY!");
    }

    else {
        for(const dataPointer& ptr : data) {
            std::lock_guard<std::mutex> lk(mt);
            ptr->operator()();
        }
    }
}
