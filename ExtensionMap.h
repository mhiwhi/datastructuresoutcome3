#ifndef EXTENSIONMAP_H
#define EXTENSIONMAP_H

#include <iostream>
#include <string>
#include <map>
#include <sstream>

class ExtensionMap {
private:
    std::map<std::string, std::string> extensions; // collection to store file extension and program
    std::string message; // message for the user

public:
    // default constructor
    ExtensionMap() {
        message = "";
    }

    // return the message
    std::string getMessage() const {
        return message;
    }

    // add an entry to the collection
    int addEntry(const std::string& k, const std::string& v) {
        // Add or update the key-value pair
        extensions[k] = v;

        // Set appropriate message
        message = "Added entry: " + k + " -> " + v;

        // Return the new size of the collection
        return extensions.size();
    }

    // remove an entry from the collection
    int removeEntry(const std::string& k) {
        // Check whether the key exists in the collection
        auto it = extensions.find(k);

        if (it != extensions.end()) {
            // Remove the corresponding key-value pair
            extensions.erase(k);
            message = "Removed entry: " + k;
        }
        else {
            // Key does not exist, set appropriate message
            message = "Error: Key '" + k + "' not found in the map";
        }

        // Return the new collection size
        return extensions.size();
    }

    // return the current size of the collection
    int getSize() const {
        return extensions.size();
    }

    // return the whole map as a String
    std::string toString() const {
        if (extensions.empty()) {
            return "{}";
        }

        std::stringstream ss;
        ss << "{";
        bool first = true;

        for (const auto& pair : extensions) {
            if (!first) {
                ss << ", ";
            }
            ss << pair.first << "=" << pair.second;
            first = false;
        }
        ss << "}";

        return ss.str();
    }

    // return a map entry
    std::string getEntry(const std::string& key) {
        // Check whether the key exists in the collection
        auto it = extensions.find(key);

        if (it != extensions.end()) {
            // Return the corresponding value
            return it->second;
        }
        else {
            // Key does not exist, set appropriate message
            message = "Error: Key '" + key + "' not found in the map";
            return "";
        }
    }
};

#endif