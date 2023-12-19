#include "Car.h"

bool Car::startEngine()
{
	cout << "Запуск двигателя автомобиля " << brand << " " << model << endl;
	return true;
}

bool Car::stopEngine()
{
	cout << "Остановка двигателя автомобиля " << brand << " " << model << endl;
	return true;
}
