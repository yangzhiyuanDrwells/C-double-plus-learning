#include<iostream>
using namespace std;
class A {
		int id;
	public:
		int j=0;
		A(int i) {
			id = i;
			cout<<id<<"gouzao"<<id<<endl;
		}
		A(const A &c){
			cout<<"�Զ��忽�����캯��"<<endl;
			id = c.id;	 
		} //������������������ģ�����a�����Ա������b�����Ա 
		void print()
		{
			cout<<this->id<<endl;
		}
		void change()
		{
			id = 6;
		}
		
};
int main() 
{
	A a(3) ;
	A b(a);
	
	a.print();
	b.print();
	
	a.change();
	
	a.print();//38,39�е����н���ó�����a�Ͷ���b�������ڴ�ռ� 
	b.print();//38,39�е����н���ó��ڽ�����a����������bʱ������b�������еĳ�Ա�ռ䣬�����ǹ�����a�Ŀռ� 
	
	return 0;

}
