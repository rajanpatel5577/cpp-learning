/*
pointer used to store the address of another variable.
we use pointers to pass variables by reference to functions,so that the function can modify the original variable.
*/

#include <iostream>
#include <string>

int main()
{
    int num = 42;    // Declare an integer variable
    int *ptr = &num; // Declare a pointer and assign it the address of num

    std::cout << "Value of num: " << num << std::endl;
    std::cout << "Address of num: " << &num << std::endl;
    std::cout << "Value stored in ptr: " << ptr << std::endl;
    std::cout << "Value pointed to by ptr: " << *ptr << std::endl; // dereference ptr to get the value of num, Output: 42

    *ptr = 100;                                            // Change the value of num using the pointer
    std::cout << "New value of num: " << num << std::endl; // Output: 100

    std::cout << std::endl;
    char *charPtr = new char('A'); // Dynamically allocate memory for a char
    std::cout << "print pointer : " << charPtr << std::endl; //print charector starting from this address to end of string
    std::cout << "print value at pointer : " << *charPtr << std::endl; //print the value stored in the address pointed by charPtr

    std::cout << std::endl;
    char *charPtr2 = new char[8]; // Dynamically allocate memory for an array of chars, block of memory for 8 characters
    charPtr2[0] = 'H';            // point to first character
    charPtr2[1] = 'e';
    charPtr2[2] = 'l';

    std::cout << std::endl;
        std::cout << "print pointer : " << charPtr2 << std::endl;
        std::cout << "print pointer value : " << *charPtr2 << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << charPtr2[i] << " "; // Output: Hel
    }
    std::cout << std::endl;

    return 0;
}