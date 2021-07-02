#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//SmallInt si(1000);

class SmallInt
{
public:
	SmallInt(int i = 0);
	//���ز���ͳ�ȡ�����
	friend ostream& operator<<(ostream& os, const SmallInt& s);
	friend istream& operator>>(istream& is, SmallInt& s);

	//�������������
	SmallInt operator+(const SmallInt& si) { return SmallInt(val + si.val); }
	SmallInt operator-(const SmallInt& si) { return SmallInt(val - si.val); }
	SmallInt operator*(const SmallInt& si) { return SmallInt(val * si.val); }
	SmallInt operator/(const SmallInt& si) { return SmallInt(val / si.val); }
	//���رȽ������
	bool operator==(const SmallInt& si) { return (val == si.val); }
private:
	char val;
};
SmallInt::SmallInt(int i)
{
	while (i > 127)
		i -= 256;
	while (i < -128)
		i += 256;
	val = i;
}
ostream& operator<<(ostream& os, const SmallInt& s)
{
	os << s.val;
	return os;
}
istream& operator>>(istream& is, SmallInt& s)
{
	int tmp;
	is >> tmp;
	s.val = tmp;
	return is;
}

int  main()
{
	SmallInt si(65);
	SmallInt si1;
	cout << si<<endl;
	cin>>si1;
	cout << si1 << endl;
	return 0;
}