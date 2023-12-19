#pragma once
#include <iostream>
#include "./Car.h"
using namespace std;
class ElectricCar : protected Car {
private:
    int batteryCapacity;
    bool EcoMode;

public:
    ElectricCar(const string& brand, const string& model, int year, int numDoors, int batteryCapacity, string engineType, bool EcoMode)
        : Car(brand, model, year, numDoors, engineType), batteryCapacity(batteryCapacity) {}

    void charge();
    void eco();
    virtual bool startEngine();

};

