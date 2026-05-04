#ifndef INTLINKEDLIST_H
#define INTLINKEDLIST_H
#include <iostream>

// Node structure for linked list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class IntLinkedList {
private:
    Node* head;
    int count;

public:
    // Constructor
    IntLinkedList() : head(nullptr), count(0) {}

    // Destructor
    ~IntLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Add element at the front (for stack LIFO behavior)
    void addFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        count++;
    }

    // Add element at the end
    void addBack(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        count++;
    }

    // Remove and return element from front
    int removeFront() {
        if (head == nullptr) {
            return -1;
        }
        Node* temp = head;
        int value = temp->data;
        head = head->next;
        delete temp;
        count--;
        return value;
    }

    // Remove and return element from back
    int removeBack() {
        if (head == nullptr) {
            return -1;
        }

        if (head->next == nullptr) {
            int value = head->data;
            delete head;
            head = nullptr;
            count--;
            return value;
        }

        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        int value = current->next->data;
        delete current->next;
        current->next = nullptr;
        count--;
        return value;
    }

    // Get element at index (0-based from front)
    int get(int index) {
        if (index < 0 || index >= count) {
            return -1;
        }

        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    // Get current size
    int size() {
        return count;
    }

    // Check if list is empty
    bool isEmpty() {
        return count == 0;
    }

    // Display all elements (from front to back)
    void display() {
        std::cout << "list has " << count << " items" << std::endl;
        Node* current = head;
        while (current != nullptr) {
            std::cout << "value: " << current->data;
            if (current->next != nullptr) {
                std::cout << " ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif