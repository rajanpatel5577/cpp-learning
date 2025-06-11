/*
map is an associative container that contains key-value pairs.
Each key is unique, and it is used to access the corresponding value.

*/
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

    // array of map
    std::map<std::string, int> marksArray[3];
    marksArray[0]["Alice"] = 85;
    marksArray[1]["Bob"] = 90;
    marksArray[2]["Charlie"] = 78;
    marksArray[0]["David"] = 92;
    marksArray[1]["Eve"] = 88;
    std::cout << "array of map display" << std::endl;
    std::cout << "arr inx 0" << std::endl;
    displayMap(marksArray[0]);
    std::cout << "arr inx 1" << std::endl;
    displayMap(marksArray[1]);
    std::cout << "arr inx 2" << std::endl;
    displayMap(marksArray[2]);

    
}