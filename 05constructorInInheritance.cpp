#include <iostream>
#include <string>

using namespace std;

class Base1
{
    int data1;

public:
    Base1(int a)
    {
        data1 = a;
        cout << "Base1 constructor called" << endl;
    }
    void displayData1()
    {
        cout << "Data1 is: " << data1 << endl;
    };
};
class Base2
{
    int data2;

public:
    Base2(int a)
    {
        data2 = a;
        cout << "Base2 constructor called" << endl;
    }
    void displayData2()
    {
        cout << "Data2 is: " << data2 << endl;
    };
};

class Derived : public Base1, public Base2
{
    int data3;

public:
    Derived(int a, int b, int c) : Base1(a), Base2(b) // Constructor initialization list
    {
        data3 = c;
        cout << "Derived constructor called" << endl;
    };
    void displayData3()
    {
        cout << "Data3 is: " << data3 << endl;
    };
};

int main()
{
    Derived a(1, 2, 3);
    a.displayData1();
    a.displayData2();
    a.displayData3();
};