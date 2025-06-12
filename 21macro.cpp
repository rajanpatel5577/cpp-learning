/*
macro use replce vaule in code
*/

#include <iostream>
#include <string>

#define OPEN_CURLY_BRACKET {
#define WAIT std::cin.get() // Macro to wait for user input

#define PR_DEGUG 1
#if PR_DEGUG == 1
#define log(x) std::cout << x << std::endl // Macro to log output
#else
#define log(x) // Empty macro for release mode
#endif

int main()
    OPEN_CURLY_BRACKET // replace with {
    log("initialize program...");
    std::cout<<"press enter key to continue..." << std::endl; 
WAIT;                      // replace with std::cin.get();
log("exiting program..."); // replace with std::cout << "exiting program..." << std::endl;
}