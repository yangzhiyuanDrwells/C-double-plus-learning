#include <iostream>
using namespace std;
int number = 0; //ȫ�ֱ����ڳ������еĹ�����ʼ�մ��ڣ������������㣩��main��ʼ��main����
				//�ڸ��������о��ܱ�����
void increase(int n)
{
	number += n;
	//number2 -= n;  //�ֲ������������������ɼ�
}
void decrease(int n)
{
	number -= n;
}
int main()
{
	//cout<<n<<endl;  //�ֲ��������뺯��ʱ��Ч���˳�ʱʧЧ���������ں̣ܶ����ڱ������ڿ��Ա�����
	int number2 = 100;
	number = 10;
	increase(1);
	cout<<number<<endl;
	decrease(2);
	cout<<number<<endl;
	cout<<number2<<endl;
	return 0;
}