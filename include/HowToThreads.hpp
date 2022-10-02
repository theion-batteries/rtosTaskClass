// CPP program to demonstrate multithreading
// using three different callables.
#include <iostream>
#include <thread>
#include <chrono>
#include <memory>
#include <string>
#include <sstream>
#include <esp_pthread.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

// A dummy function
void foo(int Z)
{
    for (int i = 0; i < Z; i++) {
        std::cout << "Thread 1 using function"
               " pointer as callable\n";
    }
}
  
// A callable object
class thread_obj {
public:
    void operator()(int x)
    {
        for (int i = 0; i < x; i++)
            std::cout << "Thread 2 using function"
                  " object as  callable\n";
    }
};
  
void test_threads()
{
    std::cout << "Threads 1 and 2 and 3 "
         "operating independently" << std::endl;
  
    // This thread is launched by using 
    // function pointer as callable
    std::thread th1(foo, 10);
  
    // This std::thread is launched by using
    // function object as callable
    std::thread th2(thread_obj(), 10);
  
    // Define a Lambda Expression
    auto f = [](int x) {
        for (int i = 0; i < x; i++)
            std::cout << "Thread 3 using lambda"
             " expression as callable\n";
    };
  
    // This thread is launched by using 
    // lamda expression as callable
    std::thread th3(f, 10);
  
    // Wait for the threads to finish
    // Wait for thread t1 to finish
    //std::cout <<"Wait for thread t1 to finish";
    th1.join();
  //
     //std::cout <<"Wait for thread t2 to finish";
    th2.join();
  //
     //std::cout <<"Wait for thread t3 to finish";
    th3.join();
  }