#include<iostream>
using namespace std;
class A
{
public:
	A()
	{
		cout<<"���캯��"<<endl;	
	}

	~A()
	{
		cout<<"��������"<<endl; 
	}
}; 
int main()
{
	A a;
	return 0;
}
