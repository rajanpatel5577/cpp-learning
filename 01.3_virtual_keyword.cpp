//when we inherit two derived class from base class then make one class from that two derived class
//last derived fuction get confuction from which base class function heerit
//Base -> Derived1
//Base -> Derived2
//Derived1 + Derived2 -> Derived3

#include <iostream>
#include <string>

using namespace std;

class Student {
    protected:
     int rollNo;

    public:
       void setRollNo(int r) {
            rollNo = r;
        }
};

class Test : virtual public Student {
    protected:
        int testScore;

    public:
        void setTestScore(int s) {
            testScore = s;
        }
};
class Sport : virtual public Student {
    protected:
        int sportScore;

    public:
        void setSportScore(int s) {
            sportScore = s;
        }
};

class Result : public Test, public Sport {
    public:
        void display() {
            cout << "Roll No: " << rollNo << endl;
            cout << "Test Score: " << testScore << endl;
            cout << "Sport Score: " << sportScore << endl;
        }
};

int main(){
    Result rajan;
    rajan.setRollNo(101);
    rajan.setTestScore(85);
    rajan.setSportScore(90);
    rajan.display();

};

//if we don't use virtual keyword then it will create two copies of Student class's roll number in Result class, one from Test and one from Sport.
//which give ambigiusty error