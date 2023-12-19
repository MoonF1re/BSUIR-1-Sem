#pragma once
#include <iostream>
#include "./Vehicle.h"
using namespace std;
class Crane : public Vehicle {
protected:
    int liftingCapacity;


public:
    Crane(const string& brand, const string& model, int year, int liftingCapacity)
        : Vehicle(brand, model, year), liftingCapacity(liftingCapacity) {}

    void lift();
    void liftStop();
};

