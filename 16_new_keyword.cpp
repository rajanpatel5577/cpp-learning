/*
new keword is used to allocate memory dynamically on the heap.
we can use new keyword with classes, structures, arrays, and primitive data types.
it create class instance and also called class constructor.
when we use new keyword, it returns a pointer to the allocated memory.
When we are done using the dynamically allocated memory, we should deallocate it using the delete keyword to avoid memory leaks.
*/

#include <iostream>
#include <string>

class MyClass
{
    int value;

public:
    MyClass(int val) : value(val) {};
};
int main()
{
    // Allocate memory for an integer using new
    int *ptr = new int(42); // Dynamically allocate memory for an integer and initialize it to 42

    std::cout << "Value of dynamically allocated integer: " << *ptr << std::endl;
    std::cout << "Address of dynamically allocated integer: " << ptr << std::endl;

    MyClass *classObjptr = new MyClass(10); 

    int *ptrArr = new int[5];

    // Deallocate memory using delete
    delete ptr;    // Free the memory allocated for the integer
    ptr = nullptr; // Set pointer to nullptr to avoid dangling pointer

    delete classObjptr;
    classObjptr =nullptr;
    delete[] ptrArr;
    ptrArr =nullptr;

    return 0;
}