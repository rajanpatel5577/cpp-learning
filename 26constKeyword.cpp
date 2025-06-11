/*
const keyword in C++ is used to define constants, which are variables whose value cannot be changed after initialization.
const int *ptr = &aeg pointer value contant
int const *ptr = &age pointer value contant
int *const ptr = &age pointer contant
const int *const ptr = &age pointer and value contant
*/

#include <iostream>
#include <string>

int main()
{
    const int MIN_AGE = 18; // Define a constant integer
    // MIN_AGE = 16; // not awllowed

    //********** */ const int *ptr = &aeg
    // cannot change the value of pointer
    // but pionter can point to different variable

    const int *agePtr = &MIN_AGE; // Pointer to a constant integer
    int age = 25;
    // *agePtr = &age; // not allowed, cannot change the value pointed to by agePtr
    std::cout << "age poniter value: " << *agePtr << std::endl;
    std::cout << "age poniter: " << agePtr << std::endl;
    std::cout << std::endl;

    agePtr = &age; // Allowed, changing the pointer to point to a different integer
    std::cout << "age poniter value: " << *agePtr << std::endl;
    std::cout << "age poniter: " << agePtr << std::endl;
    std::cout << std::endl;

    // agePtr = &MIN_AGE;
    // std::cout << "age poniter value: " << *agePtr << std::endl;
    // std::cout << "age poniter: " << agePtr << std::endl;
    // std::cout << std::endl;

    //************/  int * const ptr = &age
    // can change the value of variable pointed to by pointer
    // can't change the pointer itself to point to a different variable

    int newAge = 30;
    int *const constAgePtr = &newAge;
    std::cout << "age poniter value: " << *constAgePtr << std::endl;
    std::cout << "age poniter: " << constAgePtr << std::endl;
    std::cout << std::endl;
    *constAgePtr = 35; // Allowed, changing the value pointed to by constAgePtr
                       // constAgePtr = &age; // Not allowed, cannot change the pointer itself
    std::cout << "age poniter value: " << *constAgePtr << std::endl;
    std::cout << "age poniter: " << constAgePtr << std::endl;
    std::cout << std::endl;

    //************/ int const *ptr = &age same as const int * ptr = &age
}