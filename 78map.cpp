#include <iostream>
#include <map>
#include <string>

template <typename T1, typename T2>
void displayMap(const std::map<T1, T2> &marks) {
    for (const auto &pair : marks) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

int main() {
    std::map<std::string, int> marksMap;

    marksMap["Alice"] = 85;
    marksMap["Bob"] = 90;
    marksMap["Charlie"] = 78;

    // Adding more entries
    marksMap.insert({{"David", 92}, {"Eve", 88}});

    displayMap(marksMap);

    std::cout<< "Size of map: " << marksMap.size() << std::endl;
   std::cout<<"max size of map: " << marksMap.max_size() << std::endl;
    std::cout<<"Is map empty? " << (marksMap.empty() ? "Yes" : "No") << std::endl;

    // Accessing elements
    std::cout << "Marks of Alice: " << marksMap["Alice"] << std::endl;

    
}