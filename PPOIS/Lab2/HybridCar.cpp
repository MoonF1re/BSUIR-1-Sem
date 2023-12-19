#include "HybridCar.h"

void HybridCar::charge()
{
	cout << "Зарядка гибридного автомобиля " << brand << " " << model << endl;
}

void HybridCar::refillFuel()
{
	cout << "Заправка гибридного автомтомобиля " << brand << " " << model << endl;
}

bool HybridCar::startEngine()
{
	cout << "Запуск двигателя гибрида " << brand << " " << model << endl;
	return true;
}
