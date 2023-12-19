#include "SportCar.h"

void SportCar::stops()
{
	cout << "Машина останавливается " << brand << " " << model << endl;
}

void SportCar::drift()
{
	cout << "Машина дрифтит " << brand << " " << model << endl;
}

bool SportCar::startEngine()
{
	cout << "Запуск двигателя спорткара " << brand << " " << model << endl;
	return true;
}
