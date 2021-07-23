
//���������Ϊȫ�ֺ���
#include <iostream>
using namespace std;
class Test
{
public:
	Test(int d = 0) : m_data(d)
	{cout << "Create Test Object : " << this << endl;}
	//Test t1 = t;
	Test(const Test& t)
	{
		cout << "Copy Create Test Object : " << this << endl;
		m_data = t.m_data;
	}
	//=���� �����������
	Test& operator=(const Test& t)
	{
		cout << "Assign: " << this << " = " << &t << endl;
		if (this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	~Test()
	{cout << "Free Test Object : " << this << endl;}
public:
	int GetData()const
	{return m_data;}
	int SetData(int data)
	{m_data = data;}
private:
	int m_data;
};

Test fun(Test t)
{
	cout << "fun : " << endl;
	int value = t.GetData();
	Test tmp(value);
	return tmp;
}

ostream& operator<<(ostream& os, const Test& t)   //�������������Ϊȫ�ַ���
{
	os << t.m_data;     //ȫ�ֺ���Ҳ�޷�����Ҫ��ȫ�ֺ����޷��������˽�����ݳ�Ա
	return os;
}

int main()
{
	Test t1(100);
	Test t2, t3;
	t2 = t1; //t3.operator=( t2.operator=(t1) )
			 //t2.operator=(t1); //
	Test tmp = fun(t2);
	//cout << "t1 = " << t1 << endl;
	cout << t1;
	return 0;
}

