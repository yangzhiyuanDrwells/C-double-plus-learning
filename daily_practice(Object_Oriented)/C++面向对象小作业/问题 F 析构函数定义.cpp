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
	cout<<"��������"<<endl; //���Ķ��������룬���ӹ��캯������������
                            //�����ȷ��� 
}
}; 
int main()
{
    A a;
    return 0;
}
