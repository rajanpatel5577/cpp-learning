#include <iostream>
#include <string>
#include <chrono>
#include <thread>

void doWork()
{
    std::cout << "working...\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
}

int main()
{
    std::thread t1(doWork);
    std::cout << "thread t1  called" << std::endl;
    // std::this_thread::sleep_for(std::chrono::seconds(3));
    // t1.detach(); // thread detach even completed or not

    // use detach with joinable
    if(t1.joinable()) t1.detach();
    std::cout << "main thread execute" << std::endl;
}