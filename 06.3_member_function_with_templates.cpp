#include <iostream>
#include <string>

template <typename T>
class MyClass
{
public:
    MyClass() = default;
    // template <typename T>
    // void display(const T &value)
    // {
    //     std::cout << "Value: " << value << std::endl;
    // }
    void display(const T &value);
};

template <typename T>
void MyClass<T>::display(const T &value)
{
    std::cout << "Value: " << value << std::endl;
}

int main()
{
    MyClass<int> obj;
    MyClass<std::string> obj2;
    obj.display(42); // Display an integer
    obj2.display("hello wold!!");
};