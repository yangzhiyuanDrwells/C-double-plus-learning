#include <iostream>
#include <cmath>
#define e  2.71828182845905
using namespace std;
int main()
{
	double j = 0.005;  //��� 
	double l1 = 0.0;   //�ϵ�  
	double l2= 0.0;    //�µ� 
    double l= 0.0;
	double S = 0.0;

	double a = 0.0;    //�ϵ׿��� x
	double b = 0.005;  //�µ׿��� x
	for(int k = 0;k<200;k++)
	{
		l1 = sin(a) + pow(e,a);
		l2= sin(b) + pow(e,b);
		l = (l1+l2)/2;
		S +=  l*j;
		a += j;
		b += j;
	}
	cout << "���η����㶨���ֵ������ : " <<S<< endl;
	return 0;
}

