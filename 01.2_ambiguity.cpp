#include <iostream>
#include <string>

using namespace std;

class Base1{
    public:
    void greet() {
        cout << "Hello from Base1" << endl;
    };
};
class Base2{
    public:
    void greet() {
        cout << "Hello from Base2" << endl;
    };
};

class Derived : public Base1, public Base2 {
    // This class inherits from both Base1 and Base2
    public:
    void greet() {
        Base1::greet(); // Explicitly call greet from Base1
        // Base2::greet(); // Explicitly call greet from Base1
    }
};

// if class derived from single base class and class have also same function as base then derived class function will be called

int main(){
    Derived obj;
    obj.greet(); // Calls greet from Base1
};