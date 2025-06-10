#include <iostream>
#include <list>
#include <string>

template <typename T>
void printList(const std::list<T> &lst)
{
    for (const auto &element : lst)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main()
{

    // creating a list of integer
    std::list<int> intList = {1, 2, 3, 4, 5};
    printList(intList);

    // Create a list of strings
    std::list<std::string> myList;

    // Add elements to the list
    myList.push_back("Hello");
    myList.push_back("World");
    myList.push_back("C++");
    myList.push_back("Programming");

    // Print the elements of the list
    printList(myList);

    // iterator
    std::list<int> intList2(3); // empty list of 3
    std::list<int>::iterator it;

    it = intList2.begin(); // iterator for first list
    *it = 23;
    it++;
    *it = 34;
    it++;
    *it = 45;

    printList(intList2);

    //list methods
    std::list<int> intList3 = {10, 20, 30, 40, 50,34, 60, 70,34, 80, 90};
    intList3.push_back(56);
    intList3.push_front(12);
    intList3.remove(34); // remove all occurrences of 34
    printList(intList3);
    intList3.sort(); // sort the list
    printList(intList3);

    return 0;
}