#ifndef MYLINKEDSTACK_H
#define MYLINKEDSTACK_H
#include "StackADT.h"
#include "IntLinkedList.h"

class MyLinkedStack : public StackADT {
private:
    IntLinkedList list;

public:
    // Default constructor
    MyLinkedStack() {}

    // Adds value to stack (LIFO - at the front for O(1) push)
    void push(int value) override {
        list.addFront(value);
    }

    // Remove and return value from stack (from the front for O(1) pop)
    int pop() override {
        if (!isEmpty()) {
            return list.removeFront();
        }
        return -1; // Return -1 if stack is empty
    }

    // Returns true if the stack is empty
    bool isEmpty() override {
        return list.isEmpty();
    }

    // Returns number of items in stack
    int size() override {
        return list.size();
    }

    // Console UI for testing
    void display() override {
        list.display();
    }
};

#endif
