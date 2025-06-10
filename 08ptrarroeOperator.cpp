#include <iostream>
#include <string>

using namespace std;

class A
{
    int a;

public:
    void setValueOfA(int value)
    {
        a = value;
    };
    void printValueOfA()
    {
        ;
        cout << "the value of a is: " << a << endl;
    }
};

int main()
{

    // accessing members using dereference operator
    A a;
    // A *a1Prt = &a; // pointer to an object of class A
    A *a1Prt = new A; // dynamically allocated object
    (*a1Prt).setValueOfA(5);
    (*a1Prt).printValueOfA();

    // acessing members using arrow operator
    A *aPtr = new A;
    aPtr->setValueOfA(10); // arrow means dereference and access member
    aPtr->printValueOfA();

    // Deleting dynamically allocated memory using delete
    cout << "Deleting dynamically allocated object memory" << endl;
    delete aPtr;
    aPtr = nullptr;

    cout << "arre pointer" << endl;
    // creating array of objects dynamically
    A *aPtrArr = new A[5];
    aPtrArr->setValueOfA(11);
    aPtrArr->printValueOfA();

    (aPtrArr+1)->setValueOfA(12);
    (aPtrArr+1)->printValueOfA();
  //we can varry pointer up to 5 ( 0 to 4)


};