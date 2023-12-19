#include "Formula_1.h"

void Formula_1::accelerates()
{
	cout << "Разгоняется до максимальной скорости " << brand << " " << model << endl;
}

void Formula_1::change()
{
	cout << "Смена покрышек у машины " << brand << " " << model << endl;
}

bool Formula_1::startEngine()
{
	cout << "Запуск двигателя F1 " << brand << " " << model << endl;
	return true;
}
