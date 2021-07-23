
//�������������------>�������������Ϊ��Ա����
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
	{cout << "Free Test Object : " << this << endl;	}
public:
	int GetData()const
	{return m_data;}
	int SetData(int data)
	{m_data = data;	}
	ostream& operator<<(ostream& os)   //�������������Ϊ��Ա����
	{
		os << m_data;
		return os;
	}
private:
	int m_data;
};

Test fun(Test t)
{
	cout<<"fun : " << endl;
	int value = t.GetData();
	Test tmp(value);
	return tmp;
}

int main()
{
	Test t1(100);
	Test t2, t3;
	t2 = t1; //t3.operator=( t2.operator=(t1) )
			 //t2.operator=(t1); //
	Test tmp = fun(t2);
	//cout << "t1 = " << t1 << endl;
	t1 << cout;				//�������������Ϊ��Ա�����ö���ȥ����
	t1 << cout << endl;     //�������������Ϊ��Ա�����ö���ȥ����
	return 0;
}


