#pragma once
#include <iostream>
#include "./Vehicle.h"
using namespace std;

class Car : public Vehicle {
protected:
    int numDoors;
    string engineType;

public:
    Car(const string& brand, const string& model, int year, int numDoors, string engineType)
        : Vehicle(brand, model, year), numDoors(numDoors), engineType(engineType){}

    virtual bool startEngine();

    bool stopEngine();
};

