#include<iostream>
using namespace std;
class A {
		int id;
	public:
		int j=0;//��C98������Ĺ��г�Ա���� j�ᱻ���Ϊconst���� ��Ҫ�ڱ���ѡ���м������ʱ��������-std=c++11 
		A(int i) {
			id = i;
			cout<<id<<"gouzao"<<id<<endl;
		}
		A(A &){
			cout<<"�Զ��忽�����캯��"<<endl; 
		} //�����������������������û�а�a���󿽱���b���� 
		void print()
		{
			cout<<this->id<<endl;
		}
		void change()
		{
			id = 6;
		}
		~A() {
			cout<<id<<"xigou"<<id<<endl;
		}
		
};
int main() {
	A a(3);
	A b(a);
	cout<<"end of main"<<endl;
	cout<<a.j<<endl;
	a.print();
	b.print();
	a.change();
	a.print();
	b.print();
	return 0;
}


