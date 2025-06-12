/*
polymorphism basic means "many forms". 
one name multiple forms
polymorphism allows methods to do different things based on the object it is acting upon, even if they share the same name.
This is typically achieved through inheritance and virtual functions.

two types of polymorphism 
1)compile-time polymorphism (also known as static polymorphism)
   - function overloading
   - operator overloading
2)runtime polymorphism (also known as dynamic polymorphism)
-virtual functions
*/

#include <iostream>
#include <string>

using namespace std;

//function overloading example
void add(int a, int b){
    cout << "Sum of integers: " << a + b << endl;
};

void add(float a, float b){
    cout << "Sum of integers: " << a + b << endl;
};

//operator overloading example
class Complex {
    public:
        int real, imag;

        Complex(int r, int i) : real(r), imag(i) {}

        // Overloading the + operator
        // Complex operator%(const Complex& other){
        Complex operator+(const Complex& other){
            return Complex(real+other.real,imag+other.imag);
        };
};

int main()
{
    // compile-time polimorphism
    //1 Demonstrating function overloading (a form of compile-time polymorphism)
    //create two functions with the same name but different parameter types
    add(5, 10); // Calls the integer version of add
    add(5.50f, 10.05f); // Calls the float version of add

    //2 operator overloading (another form of compile-time polymorphism)
    //+ operator used to add two int as well as used to concatenate two strings

    // another example of + operator overloading 
    //addition of two complex numbers
    cout<< "Operator Overloading Example" << endl;
    Complex c1(1, 2),c2(3, 4),c4(5,6);
    cout<<"value of c1 : "<<c1.real << " + " << c1.imag << "i" << endl; 
    cout<<"value of c1 : "<<c2.real << " + " << c2.imag << "i" << endl; 


    Complex c3 = c1 + c2; // Uses overloaded + operator
    // Complex c3 = c1 % c2; // Uses overloaded + operator
    cout<<"value of c3 after c1 + c2 : "<<c3.real << " + " << c3.imag << "i" << endl; 

    // cout<<"value of c4 : "<<c4.real << " + " << c4.imag << "i" << endl; 
    // Complex c5 = c4 + c2; 
    // cout<<"value of c5 after c4 + c2 : "<<c5.real << " + " << c5.imag << "i" << endl; 


    // runtime polymorphism
    //3 Demonstrating runtime polymorphism using virtual functions
    // file 11polymorphism.cpp

};