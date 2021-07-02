#if 1
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
class Singleton {
public:
	static Singleton* GetInstance() {
		// ע������һ��Ҫʹ��Double-Check�ķ�ʽ���������ܱ�֤Ч�ʺ��̰߳�ȫ
		if (nullptr == _singleton) {
			_mt.lock();
			if (nullptr == _singleton) {
				_singleton = new Singleton();
			}
			_mt.unlock();
		}
		return _singleton;
	}
private:
	Singleton() {};
private:
	static Singleton* _singleton;
	static mutex _mt;
};

Singleton* Singleton::_singleton = nullptr;
mutex Singleton::_mt; 
void thread_func(int n)
{
	for (int i = 0; i < n; ++i)
		cout << Singleton::GetInstance() << endl;
}

	
int main() {
	thread t1(thread_func, 10);
	thread t2(thread_func, 10);
	t1.join();
	t2.join();

	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
	return 0;
}




#endif

#if 0
//����ģʽ
#include <iostream>
using namespace std;
class Singleton {
public:
	static Singleton* getInstance() {
		if (nullptr == _singleton)
			_singleton = new Singleton;
		return _singleton;
	}
private:
	Singleton() {};
private:
	static Singleton* _singleton;
};

Singleton* Singleton::_singleton = nullptr;

int main() {
	Singleton* i = Singleton::getInstance();
	Singleton* i1 = Singleton::getInstance();
	Singleton* i2 = Singleton::getInstance();
	Singleton* i3 = Singleton::getInstance();

	return 0;
}
#endif


#if 0
//����ģʽ
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &m_instance;
	}
private:
	// ���캯��˽��
	Singleton() {};

	// C++98 ������
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);
	// or
	// C++11
	//Singleton(Singleton const&) = delete;
	//Singleton& operator=(Singleton const&) = delete;

private:
	static Singleton m_instance;
};

Singleton Singleton::m_instance;



#endif

#if 0
//ֻ������һ������
#include <iostream>
using namespace std;
class Test {
public:
	static Test* creatInstance() {
		if (soleInstance == nullptr) 
			soleInstance = new Test;
		return soleInstance;
	}
private:
	Test() {};
private:
	static Test* soleInstance;
};
Test* Test::soleInstance = nullptr;  //��̬��Ա��������

int main() {
	Test* p = Test::creatInstance();
	Test* p1 = Test::creatInstance();
	Test* p2 = Test::creatInstance();
	return 0;
}


#endif

#if 0
//��������󿽱�
#include <iostream>
#include <boost/utility.hpp>
using namespace std;
class Test : public boost::noncopyable {

};
int main() {
	Test t1;
	//Test t2 = t1;  //���ܿ������죬������Ҫ��������͵��ȿ����������
	return 0;
}

#endif

#if 0
//��������󿽱�
#include <iostream>
using namespace std;
class Test {
public:
	Test() = default;
	Test(const Test& t) = delete;
private:
	int a = 0;
	int b = 0;
};
int main() {
	Test t1;
	//Test t2 = t1;
	Test t3;
	t3 = t1;  //����ֵ
	return 0;
}
#endif

#if 0
//��������󿽱�
#include <iostream>
using namespace std;
class Test {
public:
	Test()= default;
private:
	Test(const Test& t) {};
private:
	int a = 0;
	int b = 0;
};
int main() {
	Test t1;
	//Test t2 = t1;
	Test t3;
	t3 = t1;  //����ֵ
	return 0;
}
#endif

#if 0
//��ϰ��λnew
#include <iostream>
using namespace std;
static int mem1[10];

//���ض�λnew
void* operator new(size_t sz, int* ptr, int pos) {
	return (ptr + pos);
}

int main() {
	int* p = nullptr;
	p = new(mem1) int(998);
	return 0;
}
#endif




#if 0
//�������ڶ��ϴ���
#include <iostream>
using namespace std;
class Test {
private:
	void* operator new(size_t sz) {};
private:
	int a = 0;
	int b = 0;
};
int main() {

	return 0;
}

#endif

#if 0
//�������ڶ��ϴ���
#include <iostream>
using namespace std;
class Test
{
public:
	static Test CreateInstance()  //Ҫ�ڶ���ʵ�������󣬾͵����������̬����
	{
		return Test();
	}
	Test(const Test& c) {};  //���������캯������Ϊ����
private:
	Test() { }  //�����캯������Ϊ˽��
private:
	int a = 0;
	int b = 0;
};

int main()
{
	Test t = Test::CreateInstance();
	return 0;
}
#endif




#if 0
//ֻ�����ڶ��ϴ���
#include <iostream>
using namespace std;
class Test
{
public:
	static Test* CreateInstance()  //Ҫ�ڶ���ʵ�������󣬾͵����������̬����
	{
		return new Test;
	}
	//Test(const Test &) = delete;
private:
	Test(){ }  //�����캯������Ϊ˽��
private:
	int a = 0;
	int b = 0;
};

void main()
{
	Test t = Test::CreateInstance();
}
#endif