 #include <iostream>
#include <string>

class MyClass {
    public:
    int a;
    int b;
   mutable int c;
    void printValues() const {
        std::cout << "a: " << a << ", b: " << b << std::endl;
        // a=2; // This will cause a compilation error because this function is const
        c=2; // This is allowed because c is mutable
    }
    const int* const getPointerToA() const {
        return &a; // Returns a pointer to a constant integer
    }
    //return a pointer that can't modify, pointer pointing value can't be modified and function can't modify the class members
};

int main() {
    MyClass obj;
    obj.a = 5;
    obj.b = 10;

    obj.printValues(); 
};// 