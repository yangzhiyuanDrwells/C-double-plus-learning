#include<iostream>
using namespace std;
class A
{
	int z;
public:
	A(){cout<<"A ����"<<endl;}
	A(int m)
	{
		z = m;
		cout<<"A constructor"<<endl;
		cout<<"z: "<<z<<endl;
	}
	
	~A(){cout<<"A ����"<<endl;}
};
class point {
	int x;
	int y;
public:
	point(int a,int b)
{
	 x = a;
	 y = b;
	 cout<<"point ����"<<endl;
	 cout<<"x:  y:"<<x<<"  "<<y<<endl;
}
~point (){cout<<"point ����"<<endl;}
};
class circle : public point 
{
	A a;
	int r;
public: circle(int a,int b,int c):point (a,b),a(5)
		{
		r = c;
		cout<<"circle ����"<<endl;
		cout<<"r:"<<r<<endl;
		}
		~circle()
		{
		cout<<"circle ����"<<endl;
		}
};

int main()
{
	circle ci(1,2,3);
	return 0;
}