#include "ElectricCar.h"

void ElectricCar::charge()
{
	cout << "Зарядка электромобиля " << brand << " " << model << endl;
}

void ElectricCar::eco()
{
	cout << "Включить эконом режим у " << brand << " " << model << endl;
}

bool ElectricCar::startEngine()
{
	cout << "Запуск двигателя электрокара " << brand << " " << model << endl;
	return true;
}
