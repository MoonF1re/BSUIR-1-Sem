#include "Vehicle.h"
#include <iostream>
using namespace std;

void Vehicle::repair()
{
	cout << "Ремонт транспортного средства " << brand << " " << model << endl;
}

void Vehicle::display()
{
	cout << "Марка: " << brand << endl;
	cout << "Модель: " << model << endl;
	cout << "Год выпуска: " << year << endl;
}
