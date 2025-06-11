#include <iostream>
#include <string>
#include <vector>

template <typename T>
void displayVector(const std::vector<T> &vec)
{
    std::cout << "Vector elements: ";
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
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

    std::cout << std::endl;

    // Create a vector of strings
    std::vector<std::string> wordsVec1 = {"Hello", "World", "from", "C++"};

    std::cout << "wordsVec1 values : " << std::endl;
    displayVector(wordsVec1);

    // vector iterators
    std::vector<int> numbersVec3;
    std::vector<int>::iterator itn = numbersVec3.begin();
    numbersVec3.insert(itn, 10); // Insert at the beginning
    // numbersVec3.insert(itn + 1, 20);
    // numbersVec3.insert(itn + 2, 30); // Insert at the third position
    // iterator become invalid after first insertion so can't use as poiter every time create a new iterator
    numbersVec3.insert(numbersVec3.begin() + 1, 20); // Insert at the second position
    numbersVec3.insert(numbersVec3.begin() + 2, 30); // Insert at the third position
    std::cout << "numbersVec3 values : " << std::endl;
    displayVector(numbersVec3);
};