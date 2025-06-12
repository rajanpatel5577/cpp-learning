/*
dwfault thread is main thread
we can create onter thread inside main thread to parrelar code running

wayw to create thread
1. function pointer
2. lambda function
3. functors
4. member function
5. static member function
*/
#include <iostream>
#include <string>
#include <thread>

static bool s_finished = false;

void timeout(int seconds)
{
    std::cout << "thread id in timeout fun :  " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void doWork()
{
    std::cout << "thread id in dowork fun :  " << std::this_thread::get_id() << std::endl;

    while (!s_finished)
    {
        std::cout << "working...\n";
        timeout(1);
    }
}

void doWork2()
{
    std::cout << "thread id in dowork2 fun :  " << std::this_thread::get_id() << std::endl;

    while (!s_finished)
    {
        std::cout << "working2...\n";
        timeout(1);
    }
}

int main()
{
    std::cout << "thread id in main fun :  " << std::this_thread::get_id() << std::endl;
    std::thread worker(doWork);
    std::thread worker2(doWork2);
    std::cin.get(); // take enter key input same time while priting using dowork function
    //cin.get block entier thread but dowork function print using differrnt thread
    s_finished = true;
    worker.join();
    worker2.join();
    std::cout << "thread id in main fun :  " << std::this_thread::get_id() << std::endl;
}