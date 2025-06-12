#include <iostream>
#include <string>
#include <algorithm> // Required for sort
#include <functional> // Required for greater

// void display(int arr[]) {
//     for (auto &element : arr) {
//         std::cout << element << " ";
//     }
//     std::cout << std::endl;
// };

//

// In C++, when you pass an array to a function, it normally decays into a pointer, and the size information is lost. so above function will not work as expected.
// N represents the size of the array, which is deduced at compile time when the function is called.
// int (&arr)[N] arr is a reference to an array of integers of size N.
template <size_t N>
void display(int (&arr)[N]) {
    for (auto &element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
};

int main (){
    int arr[] = {6, 5,1, 3, 4, 5,17,12, 23, 34, 45};
    std::sort(arr, arr + 5); // Sorts the first 5 elements  
    display(arr);
    std::sort(arr, arr + 5, std::greater<int>()); //sorts the first 5 elements in descending order
}

//here, std::greater<int>() is a function object that defines a comparison operation for sorting in descending order. 
//function objects are functions wrapped in a class that can be called like a function.