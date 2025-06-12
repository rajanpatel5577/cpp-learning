#include <iostream>
#include <string>
#include <vector>

template <typename T>
void PrintValue(T a)
{
    std::cout << "Value : " << a << std::endl;
}
void squareAndPrint(int a)
{
    std::cout << "Value : " << a*a << std::endl;
}

template <typename T>
void forEach(const std::vector<T> &values, void (*func)(T))
{
    for (T value : values)
    {
        func(value);
    }
}

int main()
{
    std::vector<std::string> stringVec1 = {"hello", "from", "c++"};
    forEach(stringVec1, PrintValue);

    std::vector<int> intVector1 = {1,2,6};
        forEach(intVector1, PrintValue);
        forEach(intVector1, squareAndPrint);


}