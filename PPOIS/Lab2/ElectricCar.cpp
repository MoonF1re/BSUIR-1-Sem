#include "ElectricCar.h"

void ElectricCar::charge()
{
	cout << "������� ������������� " << brand << " " << model << endl;
}

void ElectricCar::eco()
{
	cout << "�������� ������ ����� � " << brand << " " << model << endl;
}

bool ElectricCar::startEngine()
{
	cout << "������ ��������� ����������� " << brand << " " << model << endl;
	return true;
}
