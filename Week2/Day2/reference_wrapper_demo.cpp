#include <iostream>
#include <vector>

int main() {
    int n1 = 10;
    int& ref1 = n1;

    /*
        arr is an array of size 1
        arr can store integer lvalue reference
    */
   
    // int& arr[1] {ref1};
   
    // std::vector<int&> v1 {ref1}; 
   
    /*
        if we try to make reference of a reference,
        we end up creating reference of the original data.
    */

   /*
        1) references physcally don't exist!
            - they have no storage (no memory allocated)
            - they won't have their own address

        2) references cannot be put in a container

        3) References of a reference does not work
           as intended 
   */

}