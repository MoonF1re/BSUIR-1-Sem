#include "Vehicle.h"
#include <iostream>
using namespace std;

void Vehicle::repair()
{
	cout << "������ ������������� �������� " << brand << " " << model << endl;
}

void Vehicle::display()
{
	cout << "�����: " << brand << endl;
	cout << "������: " << model << endl;
	cout << "��� �������: " << year << endl;
}
