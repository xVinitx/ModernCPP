#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Vehicle.h"

/*
    accepts pointer to an array of pointers.
    Initializes objects on heap. Store their address in
    the array.
*/

void CreateObjects(Vehicle** arr, const int size);

/*
    Lop over instances
    Calculate total price
    Divide it by number of instances
*/

float AveragePrice(Vehicle** arr, const int size);

/*
    Return _id of Vehicle with lowest price
*/

int LowestPriceId(Vehicle** arr, const int size);

// print all data members

void Display(Vehicle** arr, const int size);

#endif  // FUNCTIONALITIES_H