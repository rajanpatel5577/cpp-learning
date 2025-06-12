/*
enum uses=d for defining a set of named integral constants.
becuse if you define a intiger value directlty it can be changed
but if you define a enum value it can not be changed
mostly used for comarison and switch case
*/

#include <iostream>
#include <string>

enum Color
{
    RED,    // 0 defult initialize with zeor
    GREEN,  // 1
    BLUE,   // 2
    YELLOW, // 3
    ORANGE  // 4
};
enum errorLevel{
    INFO=1,  // 1 explicitly initialized 
    WARNING, 
    ERROR,   
    CRITICAL 
};

int main()
{
    Color myColor = RED; // Assigning an enum value
    errorLevel myError = WARNING; // Assigning an enum value

    std::cout << "Selected color: " << myColor << std::endl; // Output: 0
    std::cout << "Selected error level: " << myError << std::endl; // Output: 1

    // Using enum in a switch statement
    switch (myColor)
    {
    case RED:
        std::cout << "The color is Red." << std::endl;
        break;
    case GREEN:
        std::cout << "The color is Green." << std::endl;
        break;
    case BLUE:
        std::cout << "The color is Blue." << std::endl;
        break;
    default:
        std::cout << "Unknown color." << std::endl;
        break;
    }

    return 0;
}