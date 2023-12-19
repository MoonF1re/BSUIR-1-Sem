#pragma once
#include <iostream>
#include "./Car.h"
#include "./ElectricCar.h"
using namespace std;
class HybridCar : public Car{
private:
    int batteryCapacity;
    int fuelCapacity;

public:
    HybridCar(const string& brand, const string& model, int year, int numDoors, int batteryCapacity, int fuelCapacity, string engineType)
        : Car(brand, model, year, numDoors, engineType), batteryCapacity(batteryCapacity), fuelCapacity(fuelCapacity) {}

    void charge();

    void refillFuel();
    virtual bool startEngine();
};

