#pragma once
#include <iostream>
#include "./Vehicle.h"
using namespace std;
class Truck : public Vehicle {
protected:
    int loadCapacity;

public:
    Truck(const string& brand, const string& model, int year, int loadCapacity)
        : Vehicle(brand, model, year), loadCapacity(loadCapacity) {}

    void loadCargo();

    void unloadCargo();
};

