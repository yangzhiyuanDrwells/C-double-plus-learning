//string��ģ��ʵ��
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
class String
{
public:
	String()
	{
		//m_data = (char*)malloc(1);    //string���ͱ�����Ĭ�ϳ�ʼֵ��Ϊnull,���Բ����ٿռ�Ҳ�޿ɺ��
	}
	String(const char* str)
	{
		m_data = (char*)malloc(sizeof(char) * (strlen(str) + 1));
		strcpy(m_data, str);
	}

	String(const String& s)
	{
		m_data = (char*)malloc(sizeof(char) * (strlen(s.m_data) + 1));
		if (m_data != nullptr)
			strcpy(m_data, s.m_data);
	}
	String& operator=(const String& s)
	{
		if (this == &s)
			return *this;

		free(m_data);

		m_data = (char*)malloc(sizeof(char) * (strlen(s.m_data) + 1));
		strcpy(m_data, s.m_data);

		return *this;
	}
	~String()
	{
		free(m_data);
		m_data = NULL;
	}
private:
	char* m_data;
};

int main()
{
	String s1;
	String s2("Hello");
	String s3;
	s3 = s2;
	return 0;
}
