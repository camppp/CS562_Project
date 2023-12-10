//! \brief  The Object class declaration.
//! \author <NAME>

// Check for previous inclusion
#ifndef WMI_OBJECT_HPP
#define WMI_OBJECT_HPP

#if _MSC_VER > 1000
#pragma once
#endif

#include "Types.hpp"
#include <set>
#include <WCL/Variant.hpp>

class Object {
    // Define the Object class here
    // For example:
    int id;
public:
    Object(int id) : id(id) {}
    int getId() const { return id; }
    bool operator<(const Object& other) const {
        return id < other.id;
    }
};

class ObjectSet {
private:
    std::set<Object> objects;

public:
    // Add the necessary methods and data members to complete the ObjectSet class here
    void addObject(const Object& obj) {
        objects.insert(obj);
    }

    void removeObject(const Object& obj) {
        objects.erase(obj);
    }

    bool containsObject(const Object& obj) const {
        return objects.find(obj) != objects.end();
    }

    using iterator = std::set<Object>::iterator;
    using const_iterator = std::set<Object>::const_iterator;

    iterator begin() {
        return objects.begin();
    }

    iterator end() {
        return objects.end();
    }

    const_iterator begin() const {
        return objects.begin();
    }

    const_iterator end() const {
        return objects.end();
    }
};

#endif // WMI_OBJECT_HPP
