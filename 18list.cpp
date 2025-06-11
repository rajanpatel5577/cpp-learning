/*
list in C++ is a sequence container that allows non-contiguous memory allocation.
It is implemented as a doubly linked list, which means each element (node) contains a pointer to the next and previous elements in the list.
This allows for efficient insertion and deletion of elements at any position in the list, but accessing elements by index is slower compared to vectors.

methods of list:
- push_back(value): Adds an element to the end of the list.
- push_front(value): Adds an element to the front of the list.
- pop_back(): Removes the last element from the list.
- pop_front(): Removes the first element from the list.
- size(): Returns the number of elements in the list.
- begin(): Returns an iterator to the first element of the list.
- end(): Returns an iterator to the position just past the last element of the list.
- insert(position, value): Inserts an element at the specified position.
- erase(position): Removes the element at the specified position.
- clear(): Removes all elements from the list.
-sort(): Sorts the elements in the list.

*/
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

    // iterator and inserting elements
    std::list<int> intList2(5); // empty list of 5
    std::list<int>::iterator it;

    it = intList2.begin(); // iterator for first list
    *it = 23;
    it++;
    *it = 34;
    std::advance(it, 1); // move iterator to next position
    *it = 45;
    intList2.insert(it, 56); // insert 56 before the current position of iterator

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