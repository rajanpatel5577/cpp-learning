/*
mutual exclusion (mutual access)

race condition
whent two or more thread write same data

mutex used to avoid race condition
we use lock(), unlock() on mutex to avoid race condition
lock block second thread if first thread working

try_locak does not block second threa if first thread working return flase otherwise locak and return true

*/

#include <iostream>
#include <string>
#include <thread>
#include <mutex>

int my_amount = 0;
int my_amount2 = 0;
int my_amount3 = 0;
std::mutex m;
std::mutex m2;

void increaseAmnt(int num)
{
    for (int i = 0; i < num; i++)
    {
        my_amount++;
    };
}

void increaseAmntWithMutex(int num)
{
    for (int i = 0; i < num; i++)
    {
        m.lock(); // lock for one thread
        my_amount2++;
        m.unlock();
    };
}

//tyr_lock methid
void increaseAmntWithMutexTryLock(int num)
{
    for (int i = 0; i < num; i++)
    {
     if (m2.try_lock()) //check if locked by ither thread or not if not locked then locked and return true otherwise return false
        my_amount3++;
        m2.unlock();
    };
}

int main()
{

    std::thread t1(increaseAmnt, 200000);
    std::thread t2(increaseAmnt, 300000);
    std::thread t3(increaseAmntWithMutex, 200000);
    std::thread t4(increaseAmntWithMutex, 300000);
    std::thread t5(increaseAmntWithMutexTryLock, 200000);
    std::thread t6(increaseAmntWithMutexTryLock, 300000);


    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    std::cout << "increae witout mutex : " << my_amount << std::endl; //result may change
    std::cout << "increae with mutex : " << my_amount2 << std::endl;
    std::cout << "increae with mutex : " << my_amount3 << std::endl; //result may change
}