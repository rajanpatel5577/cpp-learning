// this pointer called that object who called member fuction
//use 1 : make same variable name in member function and class member variable
// use 2 : return object itself from member function
#include <iostream>
#include <string>

using namespace std;

class A
{
    int a;

public:
    void setA(int a)
    {
        // a = a; // this will cause ambiguity, as the parameter 'a' shadows the member variable 'a'
        this->a = a; // this pointer refers to the current object
    }
    A setAmethod2(int a)
    {
        this->a = a;  // first set value of a and then return the current object
        return *this; // returning the current object
    }
    void printA()
    {
        cout << "Value of a: " << a << endl;
    };
};

int main()
{
    A obj;
    obj.setA(10); 
    obj.printA();

    // this pointer return object itself
    A obj2 ;
    obj2.setAmethod2(20).printA(); // chaining method calls using this pointer
}