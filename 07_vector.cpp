/*
vector is dynemic array provided by STL(Standard Template Library)
vector autometially resizes itself when elements are added or removed.
store elements of same data type in contiguous memory locations.

methods of vector:
- push_back(value): Adds an element to the end of the vector.
- pop_back(): Removes the last element from the vector.
- size(): Returns the number of elements in the vector.
- begin(): Returns an iterator to the first element of the vector.
- end(): Returns an iterator to the position just past the last element of the vector.
- insert(position, value): Inserts an element at the specified position.
- erase(position): Removes the element at the specified position.
- clear(): Removes all elements from the vector.
-at(index): Returns a reference to the element at the specified index.
-sort(): Sorts the elements in the vector.
*/


#include <iostream>
#include <string>
#include <vector>

template <typename T>
void displayVector(const std::vector<T> &vec)
{
    std::cout << "Vector elements: ";
    // for (int i = 0; i < vec.size(); ++i)
    // {
    //     std::cout << vec[i] << " ";
    // }

    // for (T i :vec) // this will copy all intence of i
    for (const T &i:vec ) //pass reference to avoid copy
    {
        std::cout << i<< " ";
    }
    std::cout << std::endl;
}

int main()
{
    // Create a vector of integers
    std::vector<int> numbersVec1 = {1, 2, 3};
    std::cout << "numbersVec1 values : " << std::endl;
    displayVector(numbersVec1);

    // Create another vector of integers
    std::vector<int> numbersVec2; // zero-length vector
    numbersVec2.push_back(4);     // Add elements to the vector
    numbersVec2.push_back(5);
    numbersVec2.push_back(6);
    numbersVec2.push_back(7);
    std::cout << "numbersVec2 values : " << std::endl;
    displayVector(numbersVec2);
    numbersVec2.pop_back(); // Remove the last element
    std::cout << "numbersVec2 values : " << std::endl;
    displayVector(numbersVec2);

    //create another vector of integers
    std::vector<int> numberVec3(4,5); // Create a vector of size 4, initialized with value 5
    std::cout << "numberVec3 values : " << std::endl;
    displayVector(numberVec3);

    // Create a vector of strings
    std::vector<std::string> wordsVec1 = {"Hello", "World", "from", "C++"};
    std::cout << "wordsVec1 values : " << std::endl;
    displayVector(wordsVec1);

    std::cout << std::endl;

    // vector iterators and insert method
    std::vector<int> numbersVec4;
    std::vector<int>::iterator itn = numbersVec4.begin(); // Create an iterator for the vector
    numbersVec4.insert(itn, 10); // Insert at the beginning
    // numbersVec4.insert(itn + 1, 20);
    // numbersVec4.insert(itn + 2, 30); // Insert at the third position
    // iterator become invalid after first insertion so can't use as poiter every time create a new iterator
    numbersVec4.insert(numbersVec4.begin() + 1, 20); // Insert at the second position
    numbersVec4.insert(numbersVec4.begin() + 2, 30); // Insert at the third position
    std::cout << "numbersVec4 values : " << std::endl;
    displayVector(numbersVec4);
};