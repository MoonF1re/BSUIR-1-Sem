#include "HybridCar.h"

void HybridCar::charge()
{
	cout << "������� ���������� ���������� " << brand << " " << model << endl;
}

void HybridCar::refillFuel()
{
	cout << "�������� ���������� ������������� " << brand << " " << model << endl;
}

bool HybridCar::startEngine()
{
	cout << "������ ��������� ������� " << brand << " " << model << endl;
	return true;
}
