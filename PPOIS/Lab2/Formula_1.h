#pragma once
#include <iostream>
#include "./Car.h"
#include "./SportCar.h"
using namespace std;
class Formula_1: virtual public SportCar
{
private:
    int MaxSpeed;

public:
    Formula_1(const string& brand, const string& model, int year, int numDoors, int MaxSpeed,string engineType)
        : SportCar(brand,model,cost,year,numDoors,MaxBoost,engineType),MaxSpeed(MaxSpeed){}

    void accelerates();
    void change();
    virtual bool startEngine();

};

