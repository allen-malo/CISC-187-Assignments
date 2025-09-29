// HashTablesLab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map> // Allows us to use the std::unordered_map template class
#include <functional> // Allows us to use the std::hash template class

bool searchMap(int value, const std::unordered_map<int, bool>& map)
{
    return map.find(value) != map.end();
    // std::unordered_map#find will return the iterator to the key-value pair if found.
    // If the key is not found, the end iterator is returned.
}

void printStringToHash(std::string value)
{
    std::hash<std::string> stringHasher; // Create a hasher for std::string objects

    std::size_t nameHashValue = stringHasher(value);
    // Call the operator of the stringHasher object
    // Returns the hash value as a std::size_t, which is an unsigned integer.

    std::cout << "The string \"" << value << "\" has the hash value: \"" << nameHashValue << "\"" << std::endl;
}

int main()
{
    int array[] = { 200, 400, 100, 50, 350 };

    std::unordered_map<int, bool> map;
    // Create an ordered map to store the array elements.
    // std::unordered_map has a better average time complexity than std::map (O(1) vs O(Log_n))

    for (int element : array)
    {
        map[element] = true;
    }

    bool found = searchMap(200, map);
    std::cout << "Found: " << found << std::endl;

    std::string myName = "Allen";

    printStringToHash(myName);
}
