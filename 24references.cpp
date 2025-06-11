/*
References in C++ are an alternative to pointers, providing a way to create an alias for another variable.
They are often used to pass variables to functions without copying them, allowing for more efficient memory usage and performance.
References must be initialized when they are declared and cannot be changed to refer to another variable later.
*/

#include <iostream>
#include <string>

void incrimentByPointer(int *ptr)
{
    // *ptr++; // not use cause it will increment the pointer itself, not the value it points to and then dereference it
    (*ptr)++; // first dereference the pointer to get the value it points to, then increment that value
}

void incrimentByRefrence(int &value)
{
    value++; // increment the value directly using reference
}

int main()
{
    int num = 42;   // Declare an integer variable
    int &ref = num; // Declare a reference to num

    std::cout << "Value of num: " << num << std::endl;
    std::cout << "Value of ref: " << ref << std::endl;

    ref = 100; // Change the value of num using the reference
    std::cout << "New value of num: " << num << std::endl;
    std::cout << "New value of ref: " << ref << std::endl;

    incrimentByPointer(&num);
    std::cout << "New value of num after increment: " << num << std::endl;
    // incrimentByRefrence(ref);
    incrimentByRefrence(num);
    std::cout << "New value of num after increment by referenec: " << num << std::endl;

    int num2 = 50;
    incrimentByRefrence(num2);
    std::cout << "New value of num2 after increment by referenec: " << num2 << std::endl;

    int a = 10;
    int b = 20;
    int &refa = a;
    refa = b; // set value of b n ref b not chnage refa to point to b, but copy the value of b into a
    std::cout << "Value of a after refa = b: " << a << std::endl;
    refa = 30;
    std::cout << "Value of a : " << a << std::endl;
    std::cout << "Value of  : " << b << std::endl;
}