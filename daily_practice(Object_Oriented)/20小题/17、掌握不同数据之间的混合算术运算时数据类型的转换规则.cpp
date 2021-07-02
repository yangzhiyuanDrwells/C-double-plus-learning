#include <iostream> 
#include <typeinfo>
using namespace std;
int main() 
{	bool b = true;	
	short s = 3;
	int i = 1; 
	float f = 1.0; 
	unsigned int ui = 3;
	cout << "b type: "<< typeid(b).name() << endl;
	cout << "s type: " << typeid(s).name()<< endl;
	cout << "i type: " << typeid(i).name()<< endl;
	cout << "f type: " << typeid(f).name()<< endl;
	cout << "ui type: " << typeid(ui).name()<< endl;
	cout << "b + b type: " << typeid(b +b).name() << endl;
	cout << "'a' + 'b' type: " << typeid('a' + 'b').name() << endl;
	cout << "s + s type: " << typeid(s + s).name() << endl;
	cout << "'a' + i + f type: " << typeid('a' + i + f).name() << endl;
	cout << "'a' + 3.14 type: " << typeid('a' + 3.14).name() << endl;
	cout << "123 + 123L type: " << typeid(123 + 123L).name() <<endl;
	cout << "123L + 123U type: " << typeid(123L + 123U).name() << endl;
	cout << "123 + ui type: " << typeid(123 + ui).name() << endl;
	return 0;
}
/*
typeid �����������ڳ����п����ڻ�ȡһ�����ʽ�����͡���ͬ����֮��Ļ�������������������͵�ת���������£�
(1)�����һ��������������long double������һ��������ת��Ϊlong double��
(2)���������һ��������������double������һ��������ת��Ϊdouble��
(3)���������һ��������������float������һ��������ת��Ϊfloat��
(4)����˵����������Ϊ���������ִ����������������bool��char��unsigned char��signed char��short��unsigned short��signed char����Ϊint��
(5)����������£������һ����������������unsigned long������һ��������ת��Ϊunsigned long��
(6)���������һ����������������long int������һ����������unsigned int����ת����ȡ�����������͵���Գ��ȡ����long�ܹ���ʾunsigned int�����п���ֵ����unsigned intת��Ϊlong��
(7)���򣬽�������������ת��Ϊunsigned long��
(8)�������һ����������long������һ��������ת��Ϊlong��
(9)�������һ����������unsigned int������һ��������ת��Ϊunsigned int��
(10)�������������˴���˵����������������int���͡�*/
