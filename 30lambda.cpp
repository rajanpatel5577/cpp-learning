/*
A lambda is an anonymous function (a function without a name) that you can define directly in your code.
use to define inline function
*/

#include <iostream>
#include <string>
#include <vector>

template <typename T, typename T2>
void forEach(const std::vector<T> &values, T2 func)
{
    for (T value : values)
    {
        func(value);
    }
}

int main()
{
    std::vector<std::string> stringVec1 = {"hello", "from", "c++"};
    forEach(stringVec1, [](std::string value)
            { std::cout << "Value : " << value << std::endl; });

    std::vector<int> intVector1 = {1, 2, 6};
    forEach(intVector1, [](int value)
            { std::cout << "Value : " << value << std::endl; });

    /*the = in a lambda's capture list means "capture by value".
    This allows the lambda to make a copy of variables from the surrounding scope and use them inside the lambda,
    even after the original variables go out of scope.
    */
 int a=10;
//    forEach(intVector1, [](int value)
//             { std::cout << "Value : " << value*a << std::endl; });
   forEach(intVector1, [=](int value)
            { std::cout << "Value : " << value*a << std::endl; });

    
}