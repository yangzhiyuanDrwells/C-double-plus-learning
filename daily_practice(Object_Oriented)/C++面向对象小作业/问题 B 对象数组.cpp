#include<iostream>
using namespace std;
class Student
{
	public:
	Student()
	{
		
	}
	Student(string n,int s)
	{
		this->num = n;   /*����һ��������ó�Ա
����ʱ����������Ƚ�����ĵ�ַ����thisָ�룬Ȼ����ó�Ա
������ÿ�γ�Ա������ȡ���ݳ�Աʱ��C++������������thisָ
����ָ��Ķ�����ȷ��Ӧ��������һ����������ݳ�Ա*/ 
		this->score = s;
		cout<<num<<' '<<score<<endl;
	}
	private:
	string num;
	int score;
};
int main()
{
	string str[9][99];
	int b[99];
	int N;
	cin>>N;
	Student students[99]={};
	
	for(int i = 0;i<N;i++)
	{
		cin>>str[i][99];
		cin>>b[i];
	}
	for(int i = 0;i<N;i++)
	{
		students[i]=Student(str[i][99],b[i]);
	}
	return 0;
		
}
/*��������
5
01 89
02 78
03 56
04 92
05 76


�������
01 89
02 78
03 56
04 92
05 76
*/
