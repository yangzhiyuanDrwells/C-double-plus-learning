#include<iostream>
using namespace std;
class A
{
	public:
		int x;int y;
		A(int m,int n){
			x = m;
			y = n;
		}
	void show1(){cout<<x<<" "<<endl;} 
	void show2() const {cout<<y<<" "<<endl;	
	}	
};
int main ()
{
	const A a(1,2); //�������ڶ���ʱ�����ʼ�� 
	A const b(1,2);
//	a.x = 12; �������Ա�����������ڲ��ܱ��ı� 
//	a.show1();�������ص��ò�ͬ������ֻ�ܵ��ó���Ա���� 
	a.show2();
	return 0 ;
}
