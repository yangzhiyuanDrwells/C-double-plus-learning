#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.14159;
int main()
{
	int radius;
	double perimeter, area;
	cout << "������뾶: ";
	cin >> radius;
	perimeter = 2 * PI * radius;
	area = PI * pow(radius, 2);
	cout << "�ܳ��� : " << perimeter << endl;
	cout << "����� : " << area << endl;
	return 0;
}

