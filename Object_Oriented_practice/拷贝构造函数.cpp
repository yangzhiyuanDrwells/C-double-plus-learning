#include<iostream>
#define Debug 
using namespace std;
class Object
{	
	int id;  //���ԣ�������
public:
	Object(int u)  //�����ĳ�ʼ����������캯����Ϊ�˷����ܱ�����˽�б��� 
	{
		this->id = u;  //this-> ���thisָ��� Ŀ����Ϊ��ÿ����������Լ������ԣ�������ʱ���ʵ����Լ��Ķ�Ӧ�� 
	}
	Object(const Object & other)  //copy constructor ���������������޷���ֵ��������ʽ�ǹ̶��� 
	{
		this->id = other.id;
	}
	int change()   //��ֵ     //��������������Ϊ(��Ա������ 
	{
		this->id = 1;
	 } 
	void print()  //��ӡֵ    //��������������Ϊ(��Ա������ 
	{	
		cout<<this->id<<endl;
	}
}; 
int main()
{
	
	Object A(9);  //ֱ�ӳ�ʼ��
	A.print();
	#ifdef Debug
	Object B = A; //������ʼ��
	cout<<1<<endl;
	#endif
	#ifndef Debug
	Object B(0);  //ֱ�ӳ�ʼ�� ��int b(5) ������ʼ����int b = 5;
	  /*��C98��C11��׼���ú궨��������������ʱ����������������������ֶ������
	��˶�����뱻��ʼ����Ȼ�ᱨ�� C14�в��ᱨ�� Object B(0);�����ȳ�ʼ��0  */ 
	B = A;
	cout<<0<<endl;
	#endif
	B.print();
	
	A.change();
	A.print();
	B.print();
	
	return 0;
}
	
	

