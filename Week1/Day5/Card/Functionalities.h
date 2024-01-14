#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <memory>
#include <vector>

#include "Customer.h"

//    using alias Pointer for standard shared ptr of Customer
using Pointer = std::shared_ptr<Customer>;

//    using alias Container for standard Vector of Pointer
using Container = std::vector<Pointer>;

//    a function to create objects of type customer
void CreateObjects(Container& data) noexcept;

//    find average age of all customers
float Average(Container& data);

// function to return Nth object from the container
Pointer NthCustomer(Container& data, int N);

// function to find the age of the customer whose id is provied as a
// parameter
int AgeOfGivenCustomerId(Container& data, int id);

// function to return cvv number of debit card for customer whose Id is provided
// as a parameter
int CvvOfGivenCustomerId(const Container& data, const int id);

// function that returns the expiry date of debit card whose cvv number matches
// with value given by the user
std::string ExpityDateofCVV(const Container& data, const int cvv);

// A function to return a container of all "Pointer"s which point to customer
// with age above 50
Container CustomersAgeAbov50(const Container& data);

// A function to return the debitcard Pointer for a customer whose ID is given
// as input parameter
std::shared_ptr<DebitCard> DebitCardForGivenId(const Container& data, int id);

#endif  // FUNCTIONALITIES_H
