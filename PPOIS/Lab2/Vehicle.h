#pragma once
#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand;
    string model;
    int year;

public:
    Vehicle(const string& brand, const string& model, int year)
        : brand(brand), model(model), year(year) {}

    virtual void repair();

    virtual void display();
    
};

