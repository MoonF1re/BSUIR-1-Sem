#pragma once
#include <iostream>
#include "./Vehicle.h"
using namespace std;
class Motorcycle : public Vehicle {
protected:
    string type;
    string tireType;

public:
    Motorcycle(const string& brand, const string& model, int year, const string& type,string tireType)
        : Vehicle(brand, model, year), type(type) {}

    void drive();
    void feints();
};

