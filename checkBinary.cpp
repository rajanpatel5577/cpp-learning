#include <iostream>
#include <string>

using namespace std;

class Binary
{
    string str;

public:
    void getNumber();
    void displayNumber();
    void check_binary();
};

void Binary ::getNumber()
{
    cout << "Enter binary number" << endl;
    cin >> str;
};
void Binary ::displayNumber()
{
    cout << "You have enter" << str << endl;
};
void Binary ::check_binary()
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str.at(i) != '0' && str.at(i) != '1')
        {
            cout << "Number is not binary number!!";
            exit(0);
        }
    }
}

int main()
{
    Binary b;
    b.getNumber();
    b.displayNumber();
    b.check_binary();
    return 0;
}