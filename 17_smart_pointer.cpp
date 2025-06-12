/*
smart pointer are waraper around new keyword memory allocation
by using smart pointer you don't need to delete pointer it will done autometicaly when pointer scope is over
there are three types of smart pointer
1.unique pointer
2.shared pointer
3. weak pointer
*/

#include <iostream>
#include <string>
#include <memory> //for smart pointer


class Myclass
{

public:
    int a;
    int b;
    Myclass(int x, int y) : a(x), b(y) {};
    void printValue()
    {
        std::cout << "values of a and b : " << a << " " << b << std::endl;
    }
};

int main()
{
    // normal pointer
    {
        Myclass *normalPtr = new Myclass(2, 3);
        normalPtr->printValue();

        delete normalPtr;
        normalPtr = nullptr;
    }

    //************ unique pointer
    {
        // std::unique_ptr<Myclass> u_ptr = new Myclass(4,5); // can't use we have to call constructor explicity
        // std::unique_ptr<Myclass> u_ptr(new Myclass(4,5));
        std::unique_ptr<Myclass> u_ptr = std::make_unique<Myclass>(4, 5);
        u_ptr->printValue();
        // can't copy unique pointer
        //  std::unique_ptr<Myclass> u_ptr_copy = u_ptr; //give compilation error
    }
    //************ shared pointer
    // multiple instance can own the smae object
    // internally uses counting to track howmany shared_ptr point to object
    // when reference count drop zero the object is deleted.
    {
        {
            std::shared_ptr<Myclass> shared_ptr1;
            {
                std::shared_ptr<Myclass> shared_ptr2 = std::make_shared<Myclass>(7, 8); // count initiate 1
                shared_ptr1 = shared_ptr2;                                              // count 2
                shared_ptr2->printValue();
            }
            // shared_ptr2->printValue();
            shared_ptr1->printValue(); // count 1
        }
        // count 0
    }

    //************ weak pointer
    //weak pointer use to observe an object maaged by shared pointer
    //To access the object, you must convert (lock()) the weak_ptr to a shared_ptr. 
    //If the object has already been deleted, lock() returns nullptr.

    std::shared_ptr<Myclass> shared_ptr3 = std::make_shared<Myclass>(4,2);
    std::weak_ptr<Myclass> wp = shared_ptr3; // wp observes shared_ptr3, but does not own

    std::cout << "shared_ptr3 use_count: " << shared_ptr3.use_count() << std::endl; // 1

    if (auto shared_ptr3 = wp.lock())
    { // Try to get a shared_ptr
        std::cout << "Value: "<<shared_ptr3 << std::endl;
        shared_ptr3->printValue();
    }
    else
    {
        std::cout << "Object no longer exists\n";
    }

    shared_ptr3.reset(); // Now the managed object is deleted

    if (auto shared_ptr3 = wp.lock())
    {
        std::cout << "Value: " << shared_ptr3 << std::endl;
    }
    else
    {
        std::cout << "Object no longer exists\n";
    }
};