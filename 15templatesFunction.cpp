#include <iostream>
#include <string>

template <typename T1, typename T2>
void printAdd(T1 a, T2 b) {
    std::cout << "Sum: " << (a + b) << std::endl;
}

int main() {
    printAdd(5, 10);               // Both integers
    printAdd(5.5, 10.2);           // Both doubles
    printAdd(5, 10.2);             // Mixed types: int and double
    printAdd(("Hello, "), std::string("World!")); // Both strings
    return 0;
};
