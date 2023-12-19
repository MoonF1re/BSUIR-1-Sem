#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <string>
class Set {
private:
    std::set<std::string> elements;

public:
    // Конструктор по умолчанию
    Set() = default;

    // Конструктор с параметром
    Set(const std::string& element);


    // Конструктор с параметром
    Set(const std::vector<char>& stack);


    const std::set<std::string>& getElements() const;

    bool isEmpty() const;


    void addElement(const std::string& element);


    void removeElement(const std::string& element);

    size_t cardinality() const;

    bool contains(const std::string& element) const;

    // Операторы объединения, пересечения и разности множеств
    Set operator+(const Set& other) const;

    Set& operator+=(const Set& other);

    Set operator*(const Set& other) const;

    Set& operator*=(const Set& other);

    Set operator-(const Set& other) const;

    Set& operator-=(const Set& other);

    // Оператор []
    Set operator[](const std::string& element) const;

    void printSet(const Set& set);

    Set booleanSet(const Set& set);
};
