#ifndef INTARRAYLIST_H
#define INTARRAYLIST_H
#include <iostream>

class IntArrayList {
private:
    int* data;
    int capacity;
    int count;

public:
    // Constructor
    IntArrayList(int maxSize = 20) : capacity(maxSize), count(0) {
        data = new int[capacity];
    }

    // Destructor
    ~IntArrayList() {
        delete[] data;
    }

    // Add element at the end
    void add(int value) {
        if (count < capacity) {
            data[count++] = value;
        }
    }

    // Get element at index
    int get(int index) {
        if (index >= 0 && index < count) {
            return data[index];
        }
        return -1;
    }

    // Set element at index
    void set(int index, int value) {
        if (index >= 0 && index < count) {
            data[index] = value;
        }
    }

    // Remove element at index and return it
    int remove(int index) {
        if (index >= 0 && index < count) {
            int value = data[index];
            for (int i = index; i < count - 1; i++) {
                data[i] = data[i + 1];
            }
            count--;
            return value;
        }
        return -1;
    }

    // Get current size
    int size() {
        return count;
    }

    // Check if list is full
    bool isFull() {
        return count >= capacity;
    }

    // Check if list is empty
    bool isEmpty() {
        return count == 0;
    }

    // Display all elements
    void display() {
        std::cout << "list has " << count << " items" << std::endl;
        for (int i = 0; i < count; i++) {
            std::cout << "value: " << data[i];
            if (i < count - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
};

#endif
