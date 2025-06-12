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
    std::cout << "thread t1 called" << std::endl;
    t1.join(); // break here main thread until t1 completed
    std::cout << "further execution" << std::endl;
}     