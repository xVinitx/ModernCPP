/*
    Tasks - A   B   C

    Option 1: One after the other. Always complete one thing before starting the next task.

            Name : Single thread technique
/////////////////////////////////////////////////////////////////////////////////////////////////////////////                
    Option 2: I will complete all tasks in such a way that I "practically start all of them 
            at the same time" but keep juggling them based on some criteria.

            Name : Multi-threaded approach
/////////////////////////////////////////////////////////////////////////////////////////////////////////////            
    Option 3: Map number of tasks amongst number of available "workers" 

            Name : Parallel execution
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Option 4: Start a task. Either delegate it to another worker OR do it yourself after some time.

            If someone else is doing a task, monitor it, wait for their work to be done, take 
            follow-up actions accordingly.

            Name : Asynchronous Execution
*/


/*
    Scenario - 2 Tasks
    Calculate factorial of 5.
    Calculate square of a number given by the user.
*/

#include <future>
#include <iostream>


int square(std::future<int>& ft) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Hello from Square. I have started my work." << "\n";
    int number = ft.get();
    return number * number;
}

int factorial(int number) {
    std::this_thread::sleep_for(std::chrono::seconds(3));

    if(number < 0) {
        throw std::runtime_error("negative number error.");
    }
    if(number == 0 || number == 1) {
        return 1;
    }
    else {
        return number * factorial(number - 1);
    }
}

int main() {
    // Step 1 : Make a promise
    std::promise<int> pr;

    // Step 2 : A future linked to the promise 
    std::future<int> ft = pr.get_future();

    /*
        OS : Launch Square (if possible as a new thread)
    */

    

    std::future<int> result_ft = std::async(std::launch::async, &square, std::ref(ft));

    int val = 0;
    std::cin >> val;
    pr.set_value(val);

    std::cout << factorial(5) << "\n";
    
    std::cout << "Result of square is: " << result_ft.get() << "\n";
}


/*
    client server architecture

    future-promise model

    square calculation

    Main needs to delegate the task of square calculation

    ----> A new thread for square will be registere with OS
*/