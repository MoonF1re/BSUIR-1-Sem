#pragma once
#include <iostream>
#include "./Car.h"
using namespace std;
class SportCar : public Car {
protected:
	int MaxBoost;
	int cost;

public:
	SportCar(const string& brand, const string& model, int cost, int year, int numDoors, int MaxBoost, string engineType)
		: Car(brand, model, year, numDoors,engineType), cost(cost), MaxBoost(MaxBoost) {}

	void stops();
	void drift();
	virtual bool startEngine();
};

