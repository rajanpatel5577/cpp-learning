#include <iostream>
#include <string>

using namespace std;

class A
{
    
    
    public:
    A(int x, int y) : a(x), b(y){}  // Constructor with initialization list
    // A(int x, int y) : a(x), b(y+1){} //possible
    // A(int x, int y) : a(x+1), b(y+1){} //possible
    // A(int x, int y) : a(x+1), b(x){} //possible
    // A(int x, int y) : a(x), b(a){} //possible
    // A(int x, int y) : a(x+1), b(a){} //possible
    // A(int x, int y) : a(b), b(y){} //not possible, a is not initialized before b
    int a;
    int b;
};
int main()
{
    A obj(10, 20);
    cout << "values of and b are : " << obj.a << ", " << obj.b << endl;
};