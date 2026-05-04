// datastructuresoutcome3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyLinkedStack.h"

void linkedstackdriver() {
    MyLinkedStack astack;
    std::cout << "testing Stack" << std::endl;
    std::cout << "testing is empty " << (astack.isEmpty() ? "true" : "false") << std::endl;

    for (int i = 1; i < 6; i++) {
        astack.push(i);
    }

    std::cout << "num values in stack: " << astack.size() << std::endl;
    astack.display();
    std::cout << "popping value " << astack.pop() << std::endl;
    std::cout << "value 5 should have been removed" << std::endl;
    astack.display();
}

int main() {
    linkedstackdriver();
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
