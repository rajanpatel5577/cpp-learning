

// protected meanse meber stay private but inherit in derived class
/*
                      public derivation  private derivvation protected derivation
1. private member     Not inherited      Not inherited       Not inherited
2. public memebr      public             private             protected
3. protected membrt   protected          private             protected

*/

// private mebmber can't accessed by derived class funation
// protected member can be accessed by derived class function

#include <iostream>
#include <string>

using namespace std;

class Base
{
private:
    int a;

protected:
    int b;

public:
    int c;
    void setABC(int x, int y, int z);
    int getA();
};

void Base::setABC(int x, int y, int z)
{
    a = x;
    b = y;
    c = z;
}

int Base::getA()
{
    return a; // a is private so it can't be accessed outside the class
};

// public derived class **********************************************
class DerivedPublic : public Base
{
public:
// int getA() { return a; }; not possible private meber cant access by derived class function
int getB() { return b; }; // protected member can be accessed via derived class function
};



// private derived class **********************************************
class DerivedPrivate : private Base
{
public:
    void setABCFromPrivate(int x, int y, int z);
    int getC() { return c; };
    int getB() { return b; };
    int getAInPrivate() { return getA(); }; // private member can be accessed via public member function
};

void DerivedPrivate::setABCFromPrivate(int x, int y, int z)
{
    setABC(x, y, z); // private mebber can be access via public member function
}

// protected derived class **********************************************
class DerivedProtected : protected Base
{
public:
void setABCInProtected(int x, int y, int z);
int getC() { return c; };
int getB() { return b; };
int getAInProtected() { return getA(); }; // protected member can be accessed via public member function
};

void DerivedProtected::setABCInProtected(int x, int y, int z)
{
    setABC(x, y, z); // protected mebber can be access via public member function
}

int main()
{

    DerivedPublic dp;
    dp.setABC(1, 2, 3);
    cout << "display data by public derived class" << endl;
    cout << "value of c : " << dp.c << endl; // public member is accessible
    // cout << "value of b : "<<dp.b<<endl; // protected member is not accessible
    cout << "value of b : " << dp.getB() << endl; // protected can be accessed via public member function
    // cout << "value of a : "<<dp.a<<endl; // private member is not accessible
    // private mebmer not in herited in derived class so can't access via derived function
    cout << "value of a : " << dp.getA() << endl; //can only access via base class function

    DerivedPrivate dpr;
    // dpr.setABC(4, 5, 6); // now setABC is private so can't access directly
    dpr.setABCFromPrivate(4, 5, 6);
    cout << "display data by private derived class" << endl;
    //    cout<<"value of c : "<<dpr.c<<endl; // c now become private member so not accessible
    cout << "value of c : " << dpr.getC() << endl; //
    cout << "value of b : " << dpr.getB() << endl; 
    // cout << "value of a : " << dpr.getA() << endl;  // now getA method become private so can't access directly
    cout << "value of a : " << dpr.getAInPrivate() << endl; //we acess getA method via public member function

    DerivedProtected dprc;
    // dprc.setABC(7, 8, 9); // now setABC is protected so can't access directly
    dprc.setABCInProtected(7, 8, 9); 
    cout << "display data by protected derived class" << endl;
    // cout<< "value of c : " << dprc.c << endl; 
    cout << "value of c : " << dprc.getC() << endl; //
    cout << "value of b : " << dprc.getB() << endl; 
    cout << "value of a : " << dprc.getAInProtected() << endl;
};
