#include <iostream>
using namespace std;
class A
{
public:
	void a(int d)
{
	e = d;
	if(e%2==0) cout<<"�������Ϊż��"<<endl;

}
	void b(int d)
{
	f = d;
	if(f%2!=0) cout<<"�������Ϊ����"<<endl;
}
private : int e,f;
};
int main()
{
	A m;
	int c;
	cout<<"����һ������:"<<endl;
	cin>>c;
	m;
	m.b(c);
	return 0;
}
