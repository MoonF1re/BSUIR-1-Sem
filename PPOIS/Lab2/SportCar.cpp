#include "SportCar.h"

void SportCar::stops()
{
	cout << "������ ��������������� " << brand << " " << model << endl;
}

void SportCar::drift()
{
	cout << "������ ������� " << brand << " " << model << endl;
}

bool SportCar::startEngine()
{
	cout << "������ ��������� ��������� " << brand << " " << model << endl;
	return true;
}
