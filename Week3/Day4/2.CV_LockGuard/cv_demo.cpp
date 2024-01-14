#include <condition_variable>
#include <iostream>
#include <thread>

/*
    DisplaySquare
        - It should print the square of the number recieved as input from the user
    Main
        - Take cin input and store value in a global variable
*/

std::mutex mt;
int number = 0;
bool flag = false;
std::condition_variable cv;

void Square(){
    // condition check : each timt t1 thread is scheduled, condition must be checked
    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul, [](){ return flag; });
    std::cout << "Square of " << number << " is: " << number * number << "\n";
}

int main() {

    // step 1 : thread is registered (instantiated  and handed over to OS)
    std::thread t1(&Square);

    // step 2a : user input arrives (this can take a very long time )
    std::cin >> number;

    // step 2b : set the flag to true
    flag = true; // this specific condition is met!

    // step 3 : send a signal
    cv.notify_one(); //signal sent to main that we can now invoke the waiting thread

    t1.join();
}