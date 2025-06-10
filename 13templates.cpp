
#include <iostream>
#include <string>

using namespace std;

// Template class

template <typename T>
class vector{
    public:
    vector(T size):size(size),arr (new T(size)){};
    ~vector() {
        delete[] arr;
    };
    T getSize() const {
        return size;
    };
    T dotProduct(vector &other) const {
        T result =0;
        for(int i=0;i<size;i++){
            result += this->arr[i] * other.arr[i];
        }
        return result;
    }
    T size;
    T* arr;
};

int main() {
    vector<int> *v1ptrA=new vector<int>(3); 
    vector<int> *v1ptrB=new vector<int>(3); 

    v1ptrA->arr[0]=1;
    v1ptrA->arr[1]=2;
    v1ptrA->arr[2]=3;

    v1ptrB->arr[0]=2;
    v1ptrB->arr[1]=3;
    v1ptrB->arr[2]=4;
    cout<<"dot product result int type pointer : "<<v1ptrA->dotProduct(*v1ptrB)<<endl;


    // we can use same class for floating point numbers as well
    vector<float> *v1ptrC=new vector<float>(3); 
    vector<float> *v1ptrD=new vector<float>(3); 

    v1ptrC->arr[0]=1.1;
    v1ptrC->arr[1]=2.2;
    v1ptrC->arr[2]=3.3;

    v1ptrD->arr[0]=2.2;
    v1ptrD->arr[1]=3.3;
    v1ptrD->arr[2]=4.4;

    cout<<"dot product result float type pointer : "<<v1ptrC->dotProduct(*v1ptrD)<<endl;


}

