#include <iostream>
#include <string>
#include <chrono>

struct Time
{
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;

    Time()
    {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Time()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        std::cout << "time took : " << ms << " ms" << std::endl;
    }
};

void printFun()
{
    Time t;
    for (int i = 0; i < 100; i++)
    {
        // std::cout << i << std::endl;
        std::cout << i << "\n";
    }
}

int main()
{
    printFun(); //print take time when object destory aftre scope over
}