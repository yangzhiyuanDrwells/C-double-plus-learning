#include <iostream>
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
    A *p = new A();
    delete p;
cout<<"end of main"<<endl;
    return 0;
}
