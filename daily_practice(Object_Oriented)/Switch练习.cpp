#include<iostream>
using namespace std;
int main()
{
int ch = 1;
	switch(ch) //����
	{
	case 1:    //case�����ǳ���
		cout<<"Go to office!"<<endl;
		break;
	case 2:
	case 3:
		cout<<"Stay at home!"<<endl;
		break;
	default:
		cout<<"Do nothing!"<<endl;
		break;
	}
	return 0;
}