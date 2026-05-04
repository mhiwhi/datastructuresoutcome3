#pragma once
#ifndef MYSTACK_H
#define MYSTACK_H
#include "StackADT.h"
#include "IntArrayList.h"

class MyStack : public StackADT {
private:
    IntArrayList list;

public:
    // Default constructor sets maximum size to 20
    MyStack() : list(20) {}

    // Adds value to stack (LIFO - at the end)
    void push(int value) override {
        if (!isFull()) {
            list.add(value);
        }
    }

    // Remove and return value from stack (from the end)
    int pop() override {
        if (!isEmpty()) {
            int lastIndex = list.size() - 1;
            return list.remove(lastIndex);
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

    // Returns true if no more space
    bool isFull() override {
        return list.isFull();
    }

    // Console UI for testing
    void display() override {
        list.display();
    }
};

#endif