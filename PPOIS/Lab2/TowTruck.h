#pragma once
#include <iostream>
#include "./Vehicle.h"
using namespace std;
class TowTruck : public Vehicle {
protected:
    string towType;

public:
    TowTruck(const string& brand, const string& model, int year, const string& towType)
        : Vehicle(brand, model, year), towType(towType) {}

    void tow();
    void towStop();
};
