#include<iostream>
using namespace std;
class A{
	public:A(){cout << "A ����" << endl;}
	~A(){cout << "A ����" <<endl;}
	
	
};
class Point{
	int x,y;
	public: Point(int a,int b)
	{x=a;y=b;cout << "Point ����"<<endl;}
	~Point(){cout << "Point ����"<<endl;}
	
	
};
class Circle : public Point{
	A a;int r;
	public: Circle(int a,int b,int c):Point(a,b)
	{r=c;cout<<"Circle ����"<<endl;}
	~Circle(){cout << "Circle ����"<<endl;}
	
	
};
int main (){Circle ci(1,2,3);}

