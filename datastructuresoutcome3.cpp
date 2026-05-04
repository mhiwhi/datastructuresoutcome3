// datastructuresoutcome3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "ExtensionMap.h"

// Helper functions for testing
// add and remove kv pairs from the map with "user-friendly" messages
void mapAddRemoveTest(ExtensionMap& e) {
    e.addEntry(".txt", "Notepad++");
    std::cout << e.getMessage() << std::endl;

    e.addEntry(".html", "Mozilla Firefox");
    std::cout << e.getMessage() << std::endl;

    e.addEntry(".png", "Paint");
    std::cout << e.getMessage() << std::endl;

    e.addEntry(".pdf", "Adobe Acrobat Reader");
    std::cout << e.getMessage() << std::endl;

    e.removeEntry(".png");
    std::cout << e.getMessage() << std::endl;

    e.removeEntry(".cpp");
    std::cout << e.getMessage() << std::endl;
}

// test whether certain keys exist in the map
void mapKVexistsTest(ExtensionMap& e) {
    std::string testKeys[] = { ".docx", ".html", ".txt", ".cpp" };

    for (const std::string& s : testKeys) {
        std::string result = e.getEntry(s);
        if (result.empty()) {
            std::cout << s << " -> " << e.getMessage() << std::endl;
        }
        else {
            std::cout << s << " -> " << result << std::endl;
        }
    }
}

// Main function for testing
int main() {
    ExtensionMap em;

    std::cout << "Empty map: " << em.toString() << std::endl;
    std::cout << "..." << std::endl;

    mapAddRemoveTest(em);

    std::cout << "..." << std::endl;
    std::cout << "Map contents: " << em.toString() << std::endl;

    std::cout << "..." << std::endl;
    mapKVexistsTest(em);

    std::cout << "..." << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
