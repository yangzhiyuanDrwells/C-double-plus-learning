#include<iostream>
#include<cstring>
using namespace std;
class Test {

public:	
	Test(const char* str)   //���캯�� 
	{
		//����һ���ڴ棬������ַ���
		m_size = strlen(str) + 1;
		m_buf  = new char[m_size];
		strcpy(m_buf,str);
		cout<<&m_buf<<endl;
	}
	Test(const Test& other)   //��ӵ���ȿ������캯�� 
	{
		m_buf  = other.m_buf;
		cout<<&m_buf<<endl;
		cout<<& other.m_buf<<endl;
	}

	~Test() {
		//�ͷŴ��ַ���
		delete []m_buf;
		cout<<"00"<<endl;
	}
	const char* GetText() {
	return m_buf;
	}
private:
	int m_size;  //������ڴ��С 
	char* m_buf; //�ڴ��׵�ַ 
};

int main() 
{
	Test t1("Hellow World !");
	cout<<t1.GetText()<<endl; //printf("t1: %s \n",t1.GetText);
	Test t2(t1);  //���û�����17-19�У�����m_buf  = other.m_buf��ô����t2������t1��t2,m_bufָ����ͬһ���ڴ档
	//cout<<& t2.m_buf<<endl;
	cout<<t2.GetText()<<endl;
	return 0;
}
/*

����t1.m_bufָ��һ���ڴ棬
����t2������t1��t2,m_bufָ����ͬһ���ڴ� 

����t1������delete []m_buf;
����t2������delete []m_buf;������Ϊ�˿��ڴ��Ѿ���delete

�˴�����Dev c++�п����� ��VC 6.0�п��Կ��� 
*/







