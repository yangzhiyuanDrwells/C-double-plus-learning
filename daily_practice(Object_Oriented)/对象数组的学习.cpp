#include<iostream>
using namespace std;
class DATE 
{
	public:
	DATE() //û�в����Ĺ��캯�� = ȱʡ���� = ȱʡ�Ĺ����� 
	{
		month = day = year = 0;
		cout<< "ȱʡ�����������á�"<< endl;
//		cout<< "������������"<< day << endl; 
	}
	DATE(int m,int d,int y)
	{
		this->month = m;
		this->day = d;
		this->year = y;
		cout<< "������������"<< day << endl; 
	}
	~DATE()
	{
		cout<< "������������"<< day<<endl; 
	 } 
	void Print() const //���г�Ա���� ������ =����Ա (���ܶ����ݳ�Ա�����޸ģ�ֻ�������)
	{
		cout<< "Month = "<< month << "Day = "<< day <<"Year = "<<year<<endl;
	 } 
	
	private:
	int year,month,day; //���ݳ�Ա 
	
}; 
int main()  //�����൱�ڷ����ڴ棨�����������൱���ͷ��ڴ� �������� 
{
	DATE dates[5] = {DATE(10,1,2000),DATE(10,2,2000),DATE(10,3,2000)}; 
//�û����ŶԶ���������г�ʼ��,ʹ����DATE���������й��� 
//��5�����󣬵�ֻ����3������������������������ȱʡ���캯��

	dates[3] = DATE(10,4,2000);	//��ֵ�������ʱ��������(36,37)
	//DATE temp = DATE(10,4,2000);   temp �Ǳ�������ʱ��������  ����DATE(10,4,2000)���ǹ���Ķ��� 
	//dates[3] = temp;   ������������Ԫ�� 
	dates[4] = DATE(10,5,2000);	//��ֵ�������ʱ��������
	//DATE temp = DATE(10,5,2000);   temp �Ǳ�������ʱ��������  ����DATE(10,5,2000)���ǹ���Ķ��� 
	//dates[4] = temp;   ������������Ԫ�� 
	cout<< "�ɹ�"<<endl;
	return 0; 	
}



