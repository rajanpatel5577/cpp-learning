#include <iostream>
#include <string>

using namespace std;

int main()
{

    // Dynamic memory allocation using new keyword

    int a = 10;
    int *aPtr = new int(10); // dynamically allocated memory
    cout << "Value of a: " << a << endl;
    cout << "aPtr pointing to address: " << aPtr << endl;
    cout << "Value of aPtr pointing adress " << *aPtr << endl;
    cout << "Adress of aPtr: " << &aPtr << endl;

    int *ptrArr = new int[5]; // dynamically allocated array
    for (int i = 0; i < 5; i++)
    {
        ptrArr[i] = i + 1;
    };
    cout << "Values in ptrArr: ";
    for (int i = 0; i < 5; i++)
    {
        cout<<i<<" : " << ptrArr[i] << " ";
    };
   

    // Deleting dynamically allocated memory using delete 
    cout << endl;
    cout<< "Deleting dynamically allocated array memory" << endl;
    delete aPtr; // deallocating single integer
    cout << "aPtr pointing to address: " << aPtr << endl;
    cout << "Value of aPtr pointing adress " << *aPtr << endl;
    delete[] ptrArr; // deallocating array memory
    cout << "Values in ptrArr: ";
    for (int i = 0; i < 5; i++)
    {
        cout<<i<<" : "  << ptrArr[i] << " ";
    };
    cout << endl;

};