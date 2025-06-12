#include <iostream>
#include <string>
#include <chrono>
#include <thread>

struct Time
{
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;
    Time()
    {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Time()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        std::cout << "time took : " << ms << " ms" << std::endl;
    }
};

typedef unsigned long long ull;

ull oddSum=0,evenSum=0;

void oddSumFun(ull value){
 Time t;
    for(int i=value;i>0;i--){
        if(i%2==0){
            // std::cout<<i<<std::endl;
            oddSum +=i;
        };
    };
}

void evenSumFun(ull value){
     Time t;
    for(int i=value;i>0;i--){
        if(i%2!=0){
            evenSum +=i;
        };
    };
}

int main(){
    ull num =2000000000;
    // oddSumFun(num);
    // evenSumFun(num);
std::thread t1(oddSumFun,num);
std::thread t2(evenSumFun,num);

t1.join();
t2.join();

    std::cout <<oddSum<<std::endl;
    std::cout<<evenSum<<std::endl;
 
}
