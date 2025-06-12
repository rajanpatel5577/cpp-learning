#include <iostream>
#include <string>

using namespace std;

// base class
class Base
{
    int data1;

public:
    int data2;
    Base() {};
    void setData1and2(int a, int b);
    int getData1();

};

void Base::setData1and2(int a, int b)
{
    data1 = a;
    data2 = b;
};

int Base::getData1()
{
    return data1;
}


// derived class public
class Derived : public Base
{
    int data3;

public:
    void setData3(int a);
    void displayData();
};

void Derived::setData3(int a)
{
    data3 = a;
};
void Derived::displayData()
{
    // cout<<"data1 is : "<<data1<<endl; //private so can't accesible
    cout << "data1 is : " << getData1() << endl;
    cout << "data2 is : " << data2 << endl;
    cout << "data3 is : " << data3 << endl;
};

// derived class private
class Derived2 : Base
{
    int data3;

public:
    void setData3(int);
    void displayData();
    void processData(int,int);
};

void Derived2::setData3(int a)
{
    data3 = a;
};
void Derived2::displayData()
{
    // cout<<"data1 is : "<<data1<<endl; //private so can't accesible
    cout << "data1 is : " << getData1() << endl;
    cout << "data2 is : " << data2 << endl; //private so can't accesible 
    cout << "data3 is : " << data3 << endl;
}

void Derived2::processData(int a, int b){
    setData1and2(a,b);
}

int main()
{
    // public derived class
    Derived b;
    b.setData1and2(2,3);
    b.setData3(4);
    cout<<"display data by public derived class"<<endl;
    b.displayData();

    // private derived class
    Derived2 c;
    // c.setData1and2(2, 4); //now setData1and2 become private so cant access dirctly, we have to access setData1and2 by Derived2 function
    c.processData(5,6);
    c.setData3(7);
    cout<<"display data by private derived class"<<endl;
    c.displayData();

};