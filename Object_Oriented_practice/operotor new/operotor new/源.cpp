#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Test
{
public:
	//��Ĭ��ֵ�Ĺ��캯��Ҳ������Ĭ�Ϲ��캯����new������������Ĭ�Ϲ��캯��ȥ��ʼ�����������鲻�ܸ���ʼֵ��
	Test(int d = 0) : m_data(d)
	{
		cout << "Create Test Object : " << this << endl;
	}
	//�Զ��幹�캯��
	Test(const Test& t)
	{
		cout << "Copy Create Test Object : " << this << endl;
		m_data = t.m_data;
	}
	//����=������
	Test& operator=(const Test& t)
	{
		cout << "Assign:" << this << " = " << &t << endl;
		if (this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	//�����������������ͷŹ��캯���ڶ��Ͽ��ٵĿռ�
	~Test()
	{
		cout << "Free Test Object : " << this << endl;
	}
	void setValue(int val) {
		m_data = val;
	}
public:
	void* operator new(size_t x) {  //xΪҪ����Ķ����С
		int* tmp = (int*)malloc(x);
		return (void*)tmp;
	}
	void operator delete(void* ptr)
	{
		free(ptr);
	}
	void* operator new[](size_t x) {  //xΪҪ����Ķ�������Ĵ�С
		return malloc(x);
	}
	void operator delete[](void* ptr) {  
		/*ptr���������Ҫ��������ʼ��ַ�Ƕ���������Ԫ�ص�ַ��ǰ��һ��ָ��Ĵ�С����ƽ̨�仯: 32bit��4Byte,64bit��8Byte��
		������ͬcookieҲһ��free�ˣ���Ϊ����Ķ���������ͷ��������һ��cookie*/
		free(ptr);
	}
private:
	int m_data;
};
	



int main()
{
	//new+��������ʼֵ���ǲ�����new
	Test* pt = new Test(10);  
	//���ò�����new(operator new)���ٿռ䣬Ȼ����ù��캯����ʼ���¿��ٵĶ���10�Ǵ������캯�����ڳ�ʼ�������ֵ

	delete pt;      
	//�ȵ������������ͷŹ��캯�����ڶ��Ͽ��ٵĿռ䣬Ȼ�����delete�������ͷ��ڶ��Ͽ��ٵĶ�����ڴ�ռ�

	Test* pt1 = new Test[10];  //����һ����������
	//����ò�����new[](operotor new[])���ٿռ䣬������Ĭ�Ϲ��캯��ȥ��ʼ������˶��������ǲ��ܸ���ʼֵȥ��ʼ����

	delete[] pt1;

	return 0;
}
#endif


#if 0
//new�Ķ��������ǲ��ܳ�ʼ���ģ����ҹ��캯�������Զ���
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Test
{
public:
	~Test()
	{
		cout << "Free Test Object : " << this << endl;
	}
public:
	void* operator new[](size_t x) {  //xΪҪ����Ķ�������Ĵ�С
		return ((void*)malloc(x));
	}
private:
	int m_data;
};


int main()
{
	Test* pt1 = new Test[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//Test* pt1 = new Test[10] (1, 2, 3, 4, 5, 6, 7, 8, 9, 10 );
	return 0;
}
#endif

#if 0
/*Ĭ�Ϲ��캯�����ڵ��������new��������
��֤new����������ȷ��ǰ���ǣ�
�����幹�캯�������Զ��幹�캯����ͬʱд��Ĭ�Ϲ��캯��
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Test
{
public:
	//�Զ��幹�캯������дĬ�Ϲ��캯��new��������ᱨ��
	Test() {

	}
	//��дĬ�Ϲ��캯��ֻд���Զ��幹�캯���Ļ�new��������ᱨ��
	Test(int x) {
		m_data = x;
	}
	~Test()
	{
		cout << "Free Test Object : " << this << endl;
	}
public:
	void* operator new[](size_t x) {  //xΪҪ����Ķ�������Ĵ�С
		return ((void*)malloc(x));
	}
private:
	int m_data;
};


int main()
{
	Test* pt = new Test(10);
	Test* pt1 = new Test[10];
	return 0;
}
#endif


#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//��λnew
void* operator new(size_t sz, int* ptr, int pos)   //new������
{
	return (ptr + pos);
}
int main()
{
	int ar[10];
	new(ar, 0) int(1); //��λnew
	new(ar, 3) int(100);
	new(ar, 5) int(200);

	int* p = new int;
	return 0;
}
#endif

#if 1
#include <iostream>
using namespace std;

//���ض�λnew
void* operator new(size_t sz, int* ptr, int pos) {
	return (ptr + pos);
}

int mem1[10];
int main() {
	int mem2[10];
	int* mem3 = new int[10];

	int* p = nullptr;


	//��λnew
	//���䵽��̬��
	p = new(mem1) int(998);

	//���䵽ջ��
	p = new(mem2) int(666);

	//���䵽����
	p = new(mem3) int(999);

	p = new(mem3, 5) int(100);

	return 0;
}
#endif