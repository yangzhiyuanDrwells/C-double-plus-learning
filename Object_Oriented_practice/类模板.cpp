#include <string.h>
#include <stdio.h>
//���ڴ��double���͵Ķ��� 
class Array
{
public:
	Array(int capacity = 4)
	{
		m_buffer = new double[capacity];
		m_capacity = capacity;
		m_size = 0;
	}
	void PushBack(double val) // 
	{
		
	}
private:
	double *m_buffer; //����һ����*m_buffer������ 
	int m_capacity;   //���� 
	int m_size;       //�Ѿ���ŵĶ���ĸ��� 
};

int main()
{
	Array a;
	a.PushBack(1);
	a.PushBack(2);
	a.PushBack(3);
	a.PushBack(4);
	a.PushBack(5);
}

