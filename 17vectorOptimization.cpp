#include <iostream>
#include <string>
#include <vector>

class Car {
    public:
    std::string make; 
    std::string model; 
    std::string price; 
    Car(std::string a,std::string b,std::string c):make(a),model(b),price(c){}
    void display(){
        std::cout<<"make : "<< make<<" ";
        std::cout<<"model : "<< model<<" ";
        std::cout<<"price : "<< price<<" ";
        std::cout<<std::endl;
    }
};

int main(){
    std::vector<Car> carVecArr1;

    carVecArr1.reserve(3); // reserve three place so don't make double copy
    carVecArr1.push_back(Car("audi","A4","5000")); // this method make copy for creating vector
    carVecArr1.emplace_back("tata","Nexon","2000");
    carVecArr1.emplace_back("maruti","swift","1000");

    for(Car & v : carVecArr1){
        v.display();
    };

 


}