/*
abstract class means that only create for the purpose of inheritance,
this class itself cannot be instantiated but can be used to create derived classes.

normal virtual function if you not define same function in any derived class then base class function will be called
but if you define pure virtual function in base class then you must define that function in derived class otherwise compiler will give error

*/

#include <iostream>
#include <string>

using namespace std;

// abstract class
class Base
{
public:
    void virtual printValue(){};
    // void virtual printValue()=0;{}; // pure virtual function, inforced to override in derived classes
};

class DerivedA : public Base
{
public:
    DerivedA() {};
    void printValue()
    {
        cout << "print function from Derived A class" << endl;
    };
};

// not declairing printValue function in DerivedB class
class DerivedB : public Base
{
public:
    DerivedB() {};
    // void printValue()
    // {
    //     cout << "print function from Derived B class" << endl;
    // };
};

int main()
{

    Base *baseDerivedAPtr = new DerivedA;
    Base *baseDerivedBPtr = new DerivedB;
    baseDerivedAPtr->printValue();
    baseDerivedBPtr->printValue();
};