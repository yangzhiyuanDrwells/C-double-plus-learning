#include<iostream>
using namespace std;

class Int
{
public:
	Int(long i = 0) : m_i(i)
	{}
	Int(const Int& x)
	{
		this->m_i = x.m_i;
	}
public:
	Int operator+(const Int& x)
	{
		return Int(this->m_i + x.m_i);
	}
	Int operator-(const Int& x)
	{
		return Int(this->m_i - x.m_i);
	}
	Int operator*(const Int& x)
	{
		return Int(this->m_i * x.m_i);
	}
	Int operator/(const Int& x)
	{
		return Int(this->m_i / x.m_i);
	}
	Int operator%(const Int& x)
	{
		return Int(this->m_i % x.m_i);
	}
public:
	Int& operator+=(const Int& x) // a += b;
	{
		this->m_i = this->m_i + x.m_i;
		return *this;
	}
	Int& operator-=(const Int& x)
	{
		this->m_i = this->m_i - x.m_i;
		return *this;
	}
	Int& operator*=(const Int& x)
	{
		this->m_i = this->m_i * x.m_i;
		return *this;
	}
	Int& operator/=(const Int& x)
	{
		this->m_i = this->m_i / x.m_i;
		return *this;
	}
	Int& operator%=(const Int& x)
	{
		this->m_i = this->m_i % x.m_i;
		return *this;
	}
public:
	Int operator>>(const Int& x) //a >> b
	{
		return(Int(this->m_i >> x.m_i));
	}
	Int operator<<(const Int& x)
	{
		return(Int(this->m_i << x.m_i));
	}
	Int& operator>>=(const Int& x)
	{
		this->m_i = this->m_i >> x.m_i;
	}
	Int& operator<<=(const Int& x)
	{
		this->m_i = this->m_i << x.m_i;
	}
public:
	bool operator==(const Int& x)
	{
		return (this->m_i == x.m_i);
	}
	bool operator!=(const Int& x)
	{
		return (this->m_i != x.m_i);
	}
public:
	Int operator++() //ǰ��++    �Ⱥ���++Ч��    �������÷���
	{
		this->m_i++;
		return *this;
	}
	Int operator++(int)  //����++
	{
		Int temp(*this);  //���ÿ������캯�������ù��캯��
		//Int temp(this->m_i);
		this->m_i++;      //*this++
		return temp;
	}
	Int operator--() //ǰ��--
	{
		this->m_i--;
		return Int(*this);
	}
	Int operator--(int)  //����--
	{
		Int temp(*this);  //���ÿ������캯��
		this->m_i--;
		return temp;
	}
public:
	int GetData()const
	{
		return this->m_i;
	}
private:
	long m_i;
};

int main()
{
	Int a(1);  //int a = 1;  a++  ++a  a-- --a
	Int b(2);

	cout << "a = " << a.GetData() << endl;
	cout << "b = " << b.GetData() << endl;

	Int result;
	result = a + b; //result = 1 + 2;
	cout << "result = " << result.GetData() << endl;

	result = ++a;

	return 0;
}
