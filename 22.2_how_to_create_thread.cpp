#include <iostream>
#include <string>
#include <chrono>
#include <thread>

void doWork(int x)
{
    std::cout << x << std::endl;
}

int main()
{
    //   1. function pointer
    std::thread tfp(doWork,10);
    
    // 2. lambda function
    auto threadFun = [](int x)
    {
        std::cout << x << std::endl;
    };
    std::thread tlmd(threadFun, 10);

    // 3. functors (function object)
    class Base
    {
    public:
        void operator()(int x)
        {
            std::cout << x << std::endl;
        }
    };
    std::thread tftr((Base()), 10);

    // 4. member function
    class Base2
    {
    public:
        void doWork(int x)
        {
            std::cout << x << std::endl;
        }
    };
    Base2 b;
    std::thread tmfun(&Base2::doWork, &b, 10);

    // 5. static member function
    class Base3
    {
    public:
        static void doWork(int x)
        {
            std::cout << x << std::endl;
        }
    };
    std::thread tstfun(&Base3::doWork, 10);

    tfp.join();
    tlmd.join();
    tftr.join();
    tmfun.join();
    tstfun.join();
}