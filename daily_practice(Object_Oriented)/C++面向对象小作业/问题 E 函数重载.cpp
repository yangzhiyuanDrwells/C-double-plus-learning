#include<iostream>
using namespace std;

//������Ķ����������ط���
//�ڴ˴�������غ�����ʹ�ó���Ҫ����������� 
int max(int x,int y)
{
	cout<<"int compare ";
	return x>y?x:y;
}
double max(double x,double y)
{
	cout<<"double compare ";
	return x>y?x:y;
}
int main()
{
cout<<max(4,5)<<endl;
cout<<max(45.23,2.3)<<endl;
    return 0;
}
