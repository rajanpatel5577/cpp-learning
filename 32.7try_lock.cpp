/*
std::try_lock(m1,m2,m3...mn)
we can check multiple mutex vaues are lock or not by using try_lock directly
*/

#include <iostream>
#include <string>
#include<thread>
#include<mutex>

int X=0,Y=0;
std::mutex m1,m2;

void incrementXY(int &XorY, std::mutex &m, const char* desc ) {
    for (int i=0;i<5;i++){
        m.lock();
        ++XorY;
        std::cout<<desc<<XorY<<std::endl;
        m.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void consumeXY () {
    int useCount =5;
    int XplusY =0;

    while(1){
        int lockResult = std::try_lock(m1,m2);
        if(lockResult == -1){
            if(X!=0 && Y!=0){
                --useCount;
                XplusY+=X+Y;
                X=0;
                Y=0;
                std::cout<<"XplusY" <<XplusY<<std::endl;
            }
            m1.unlock();
            m2.unlock();
            if(useCount ==0) break;
        }
    }
}

int main(){
    std::thread t1(incrementXY,std::ref(X),std::ref(m1),"X");
    std::thread t2(incrementXY,std::ref(Y),std::ref(m1),"Y");
    std::thread t3(consumeXY);

        t1.join();
    t2.join();
    t3.join();
    return 0;

}