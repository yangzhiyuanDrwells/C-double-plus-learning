#include <iostream>
using namespace std;
int main()
{
	int a[999] ;
	cout<<"������һ��n,��������쳲��������еĵ�n���ǰn��֮��" <<endl;
	int n;
	cin>>n;
	int  N; 
	int S = 1;
 
	a[0] = 0;
	a[1] = 1;
	for(int i = 0;i<n-2;i++)
{
	a[i+2] = a[i] + a[i+1];
	S += a[i+2];
	N = a[i+2];
}

	cout <<"��n�� = "<<N<< endl;
	cout <<"ǰn��� = "<<S<< endl;
	return 0;
}
