#ifndef SETADT_H
#define SETADT_H
#include <vector>
#include <algorithm>

class SetADT {
private:
    std::vector<const void*> elements;  // Store pointers to objects

    // Helper function to find an object in the set
    int find(const void* o) {
        for (size_t i = 0; i < elements.size(); i++) {
            if (elements[i] == o) {
                return i;
            }
        }
        return -1;
    }

public:
    // Adds an object to the set
    void add(void* o) {
        if (find(o) == -1) {
            elements.push_back(o);
        }
    }

    // Removes object o from the set
    void remove(void* o) {
        int index = find(o);
        if (index != -1) {
            elements[index] = elements.back();
            elements.pop_back();
        }
    }

    // Sets this set to the intersection of itself and s
    void intersection(SetADT& s) {
        std::vector<const void*> newElements;
        for (size_t i = 0; i < elements.size(); i++) {
            if (s.contains(elements[i])) {
                newElements.push_back(elements[i]);
            }
        }
        elements = newElements;
    }

    // Sets this set to the difference between itself and s
    void difference(SetADT& s) {
        std::vector<const void*> newElements;
        for (size_t i = 0; i < elements.size(); i++) {
            if (!s.contains(elements[i])) {
                newElements.push_back(elements[i]);
            }
        }
        elements = newElements;
    }

    // Returns the number of objects in the set
    int size() {
        return elements.size();
    }

    // Returns true if size = 0, else false
    bool isEmpty() {
        return elements.empty();
    }

    // Helper method to check if set contains an object
    bool contains(const void* o) {
        return find(o) != -1;
    }
};

#endif