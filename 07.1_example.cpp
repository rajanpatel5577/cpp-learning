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
    std::vector<Car> carVecArr;

    carVecArr.push_back({"audi","A4","5000"});
    carVecArr.push_back({"tata","Nexon","2000"});
    carVecArr.push_back({"maruti","swift","1000"});

    for(Car & v : carVecArr){
        v.display();
    };

    std::cout<<std::endl;
    carVecArr.erase(carVecArr.begin()+2); //delete third element
    std::cout<<"print after erase"<<std::endl;
        for(Car & v : carVecArr){
        v.display();
    };


}