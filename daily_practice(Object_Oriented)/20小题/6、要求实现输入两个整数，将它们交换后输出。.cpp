#include <iostream>
using namespace std;
int main()
{
	int a,b;   //
	int temp;
	cout << "��ֱ�����������a,b: ";
	cin >>a>>b;
	temp = a;
	a = b;
	b = temp;
	cout << "�����ǽ��������" <<"a = "<<a<<"b = "<<b<< endl;
	return 0;
}
