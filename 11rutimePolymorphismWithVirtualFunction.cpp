#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
   Base() : baseValue(0) {}; // Default constructor
    Base(int value) : baseValue(value) {};
    int baseValue;
    void  printValue() 
    // void virtual printValue() // Virtual keywor to use function by runtime polymorphism
    //virtual keyword useed to override the default behavior of function call
    {
        cout<<"print function from Base class"<<endl;
        cout << "Base value: " << baseValue << endl;
    };
};
class Derived : public Base
{
public:
    Derived(int value) : derivedValue(value) {};
    int derivedValue;
    void printValue()
    {
        cout<<"print function from Derived class"<<endl;
        cout << "derivedValue value: " << derivedValue << endl;
    };
};

int main()
{
    Base *basePtr = new Base(4);
    Derived *derivedPtr = new Derived(5);
    basePtr->printValue(); //print from Base class
    derivedPtr->printValue(); //print from Derived class

    Base *baseDerivedPtr = new Derived(6); // Base pointer pointing to Derived object
    baseDerivedPtr->printValue(); // Calls Derived's printValue due to runtime polymorphism if virtual keyword used
};