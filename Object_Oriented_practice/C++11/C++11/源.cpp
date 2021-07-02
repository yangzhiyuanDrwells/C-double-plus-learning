#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <forward_list>
#include <functional>  //�º���
#include <array>
#include <set>
#include <thread>
using namespace std;

#if 1


#endif

#if 1


#endif

#if 0
//weak_ptr
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
using namespace std;
int main() {
	int* p = new int(1);
	boost::shared_ptr<int> sp(p);
	cout << "use_count " << sp.use_count() << endl;
	boost::weak_ptr<int> wp(sp);
	cout << "use_count " << sp.use_count() << endl;

	return 0;
}
//weak_ptr���ڽ��ѭ�����õ�����

#endif

#if 0
//shared_ptr
#include <iostream>
#include <boost/shared_ptr.hpp>
using namespace std;
int main() {
	int* p = new int(1);
	boost::shared_ptr<int> sp(p);
	cout << *p << endl;

	cout << "use_count" << sp.use_count()<< endl;

	//����������
	boost::shared_ptr<int> sp1(sp);
	cout << "use_count" << sp.use_count() << endl;

	//����ֵ
	boost::shared_ptr<int> sp2;
	sp2 = sp;
	cout << "use_count" << sp.use_count() << endl;

	return 0;
}
#endif

#if 0
//scoped_array
#include <iostream>
#include <boost/smart_ptr.hpp>
using namespace std;

int main() {
	int* pa = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	boost::scoped_array<int> spa(pa);
	for (int i = 0; i < 10; ++i)
		cout << spa[i] << " ";
	cout << endl;

	//��ֹ��������͸�ֵ
	//boost::scoped_array<int> spa1(spa);

	return 0;
}
#endif



#if 0
//scoped_ptr
#include <iostream>
#include <boost/smart_ptr.hpp>
using namespace std;
int main() {
	int* p = new int(10);
	boost::scoped_ptr<int> sptr(p);

	cout << *sptr << endl;
	//scoped_ptr��ֹ��������͸�ֵ����
	//boost::scoped_ptr<int> sptr1(sptr);

	//����ָ���ÿ�
	sptr.reset();
	return 0;
}
#endif


#if 0
//auto_ptr
#include <iostream>
#include <memory>
using namespace std;
/*
memory��C++�ռ��������Լ�new delete�����ͷ�ļ������涨���˿ռ���������
new delete�Լ�һЩ���ڵ��ù��캯���ĺ�����
*/

class test {
public:
	test() {
	}
	void func() {
		cout << "test::func is called" << endl;
	}
};

int main() {
	int* p = new int(10);
	auto_ptr<int> ap(p);
	cout << *ap << endl;
	*ap = 100;
	cout << *p << endl;

	test* tP = new test;
	auto_ptr<test> ap2Test(tP);
	tP->func();
	return 0;
}

#endif

#if 0
#include <iostream>
#include <mutex>
using namespace std;
mutex mu;
int main() {
	unique_lock<mutex> ug1(mu);
	unique_lock<mutex> ug2 = move(ug1);  //�ƶ�����

	unique_lock<mutex> ug3(mu);
	unique_lock<mutex> ug4;
	ug4 = move(ug3);  //�ƶ���ֵ
	return 0;
}
#endif

#if 0
//lock_guard
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
int number = 0;
mutex g_lock;
int ThreadProc1()
{
	for (int i = 0; i < 100; i++)
	{
		lock_guard<mutex> lck(g_lock);
		++number;
		cout << "thread 1 :" << number << endl;
	}
	return 0;
}
int ThreadProc2()
{
	for (int i = 0; i < 100; i++)
	{
		g_lock.lock();
		--number;
		cout << "thread 2 :" << number << endl;
		g_lock.unlock();
	}
	return 0;
}
int main()
{
	thread t1(ThreadProc1);
	thread t2(ThreadProc2);
	t1.join();
	t2.join();
	cout << "number:" << number << endl;
	system("pause");
	return 0;
}
#endif

#if 0
//mutex������
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
int number = 0;
mutex g_lock;
int ThreadProc1()
{
	for (int i = 0; i < 100; i++)
	{
		g_lock.lock();
		++number;
		cout << "thread 1 :" << number << endl;
		g_lock.unlock();
	}
	return 0;
}
int ThreadProc2()
{
	for (int i = 0; i < 100; i++)
	{
		g_lock.lock();
		--number;
		cout << "thread 2 :" << number << endl;
		g_lock.unlock();
	}
	return 0;
}
int main()
{
	thread t1(ThreadProc1);
	thread t2(ThreadProc2);
	t1.join();
	t2.join();
	cout << "number:" << number << endl;
	system("pause");
	return 0;
}
#endif


#if 0
#include <iostream>
#include <thread>
#include <atomic>
using namespace std;
//atomic_ulong sum = 0L;

atomic<unsigned long> sum(0L);

void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i) 
		sum++;
}
int main()
{
	cout << "Before joining,sum = " << sum << std::endl;
	thread t1(fun, 10000000);
	thread t2(fun, 10000000);
	t1.join();
	t2.join();
	cout << "After joining,sum = " << sum << std::endl;  //���С��2000w
	return 0;
}
#endif


#if 0
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
unsigned long sum = 0L;

mutex mu;
void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i) {
		mu.lock();
		sum++;
		mu.unlock();
	}
}
int main()
{
	cout << "Before joining,sum = " << sum << std::endl;
	thread t1(fun, 10000000);
	thread t2(fun, 10000000);
	t1.join();
	t2.join();
	cout << "After joining,sum = " << sum << std::endl;  //���С��2000w
	return 0;
}
#endif


#if 0
#include <iostream>
#include <thread>
using namespace std;
unsigned long sum = 0L;

void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
		sum++;
}
int main()
{
	cout << "Before joining,sum = " << sum << std::endl;
	thread t1(fun, 10000000);
	thread t2(fun, 10000000);
	t1.join();
	t2.join();
	cout << "After joining,sum = " << sum << std::endl;  //���С��2000w
	return 0;
}
#endif

#if 0
void ThreadFunc() { cout << "ThreadFunc()" << endl; }
bool DoSomething() { return false; }
int main()
{
	thread t(ThreadFunc);
	t.detach();
	if (!DoSomething())
		return -1;
	return 0;
}
#endif

#if 0
class agent {
public:
	agent(thread& th) :_th(th) {
	}
	~agent() {
		auto lam = [this]()->void {this->_th.join(); };
		if (_th.joinable()) lam();
	}
private:
	thread& _th;
};

void ThreadFunc() { cout << "ThreadFunc()" << endl; }
bool DoSomething() { return false; }
int main()
{
	thread t(ThreadFunc);
	agent a(t);
	
	if (!DoSomething())
		return -1;

	return 0;
}
#endif

#if 0
class agent {
public:
	agent(thread & th):_th(th) {
	}
	~agent() {
		if (_th.joinable())
			_th.join();
	}
private:
	thread &_th;
};

void ThreadFunc() { cout << "ThreadFunc()" << endl; }
bool DoSomething() { return false; }
int main()
{
	thread t(ThreadFunc);
	agent a(t);
	if (!DoSomething())
		return -1;
	return 0;
}
#endif

#if 0
void ThreadFunc() { cout << "ThreadFunc()" << endl; }
bool DoSomething() { return false; }
int main()
{
	std::thread t(ThreadFunc);
	if (!DoSomething())
		return -1;
	t.join();
	return 0;
}
//�����޷����е�join�ͻ������Ҳ�������̵߳���Դû�б��������߳��Ѿ��˳����������
#endif


#if 0
#if 0
void thread_fun(int& x)
{
	x += 100;
	cout << "This is thread fun." << endl;
}

void main()
{
	int a = 10;
	cout << "a = " << a << endl;
	thread th1(thread_fun, a);
	th1.join();
	cout << "a = " << a << endl;
}
#else
void func(int& data) {
	data += 10000;  
	cout << "child thread data: " << data << endl;
}

int main() {
	int data = 10;
	thread td(func, data);
	td.join();
	cout << "main thread data: " << data << endl;
	return 0;
}
#endif

#endif


#if 0
void func(int* data) {
	*data += 10000;  //�̺߳����Ĳ�������ֵ�����ķ�ʽ�������߳�ջ�ռ�
	cout << "child thread data: " << *data << endl;
}

int main() {
	int data = 10;
	thread td(func, &data);
	td.join();
	cout << "main thread data: " << data << endl;
	return 0;
}
#endif

#if 0
void func(int &data) {
	data += 10000;  //�̺߳����Ĳ�������ֵ�����ķ�ʽ�������߳�ջ�ռ�
	cout << "child thread data: " << data << endl;
}

int main() {
	int data = 10;
	thread td(func, ref(data));
	td.join();
	cout << "main thread data: " << data << endl;
	return 0;
}

#endif



#if 0
void func(int data) {
	data += 10000;  //�̺߳����Ĳ�������ֵ�����ķ�ʽ�������߳�ջ�ռ�
	cout << "child thread data: " << data << endl;
}

int main() {
	int data = 10;
	thread td(func, data);
	td.join();
	cout << "main thread data: "<<data << endl;
	return 0;
}
#endif

#if 0
void treadFunc() {
	cout << "I am child tread!" << endl;
}
int main() {
	thread td1(treadFunc);
	thread td2 = move(td1);  //�ƶ����죺error

	thread td3(treadFunc);
	thread td4;
	td4 = move(td3);  //�ƶ���ֵ�� error

	td2.join();
	td4.join();
	return 0;
}

#endif

#if 0
void treadFunc() {
	cout << "I am child tread!" << endl;
}
int main() {
	thread td1(treadFunc);
	thread td2 = td1;  //�������죺error

	thread td3;
	td3 = td1;  //��ֵ�� error
	return 0;
}

#endif

#if 0
#include <iostream>
using namespace std;
#include <thread>
void ThreadFunc(int a)
{
	cout << "Thread1" << a << endl;
}
class TF
{
public:
	void operator()()
	{
		cout << "Thread3" << endl;
	}
};
int main()
{
	// �̺߳���Ϊ����ָ��
	thread t1(ThreadFunc, 10);
	// �̺߳���Ϊlambda���ʽ
	thread t2([] {cout << "Thread2" << endl; });
	// �̺߳���Ϊ�������󣬷º���
	TF tf;
	thread t3(tf);
	t1.join();
	t2.join();
	t3.join();
	cout << "Main thread!" << endl;
	return 0;
}
#endif

#if 0
void thread_fun(int n, int m)
{
	for (int i = 0; i < n; ++i)
		cout << "This is Child Thread." << endl;
}

int main()
{
	int n = 5;
	int m = 10;
	thread th(thread_fun, n, m);
	cout << th.get_id() << endl;
	//th.detach();
	cout << th.get_id() << endl;
	for (int i = 0; i < 10; ++i)
		cout << "This is Main Thread." << endl;

	th.join();  //���߳������ȴ�,�������߳���Դ����������Դ����ᱼ��
	cout << "Main End." << endl;
	return 0;
}

#endif


#if 0
void Fun(int& x) { 
	cout << "lvalue ref" << endl; 
}
void Fun(int&& x) { 
	cout << "rvalue ref" << endl; 
}
void Fun(const int& x) { 
	cout << "const lvalue ref" << endl; 
}
void Fun(const int&& x) { 
	cout << "const rvalue ref" << endl;
}
template<typename T>
void PerfectForward(T&& t) {
	Fun(std::forward<T>(t)); 
}
int main()
{
	PerfectForward(10); // rvalue ref
	int a;
	PerfectForward(a); // lvalue ref
	PerfectForward(std::move(a)); // rvalue ref
	const int b = 8;
	PerfectForward(b); // const lvalue ref
	PerfectForward(std::move(b)); // const rvalue ref
	return 0;
}
#endif

#if 0
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String(String&& s) :_str(s._str) {
		s._str = nullptr;
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}
	String operator+(const String& s)
	{
		char* pTemp = new char[strlen(_str) + strlen(s._str) + 1];
		strcpy(pTemp, _str);
		strcpy(pTemp + strlen(_str), s._str);
		String strRet(pTemp);
		return strRet;
	}
	~String()
	{
		if (_str) delete[] _str;
	}
private:
	char* _str;
};

class Person
{
public:
	Person(const char* name, const char* sex, int age)
		: _name(name)
		, _sex(sex)
		, _age(age)
	{}
	Person(const Person& p)
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}
#if 0
	Person(Person&& p)  //
		: _name(p._name)
		, _sex(p._sex)
		, _age(p._age)
	{}
#else
	Person(Person&& p)  //��ȷʹ����ȫ�ƶ�����
		: _name(move(p._name))
		, _sex(move(p._sex))
		, _age(p._age)
	{}
#endif
private:
	String _name;
	String _sex;
	int _age;
};
Person GetTempPerson()
{
	Person p("prety", "male", 18);
	return p;
}
int main()
{
	Person p(GetTempPerson());
	return 0;
}

#endif

#if 0
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String(String&& s) :_str(s._str) {
		s._str = nullptr;
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}
	String operator+(const String& s)
	{
		char* pTemp = new char[strlen(_str) + strlen(s._str) + 1];
		strcpy(pTemp, _str);
		strcpy(pTemp + strlen(_str), s._str);
		String strRet(pTemp);
		return strRet;
	}
	~String()
	{
		if (_str) delete[] _str;
	}
private:
	char* _str;
};
int main() {
	String s1("hello");
	//String s2 = s1;  
	/*��s1��������s2�����õ�����ͨ�Ŀ������췽��Ҳ���ǽ����������
	Ҫ����������ƶ��������췽������ǳ��������ô�͵���=�ұ�����ֵ����*/
	String s2 = move(s1);
	return 0;
}
#endif


#if 0
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
		String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}
	String operator+(const String& s)
	{
		char* pTemp = new char[strlen(_str) + strlen(s._str) + 1];
		strcpy(pTemp, _str);
		strcpy(pTemp + strlen(_str), s._str);
		String strRet(pTemp);
		return strRet;
}
	~String()
	{
		if (_str) delete[] _str;
	}
private:
	char* _str;
};
int main()
{
	String s1("hello");
	String s2("world");
	String s3(s1 + s2);
	return 0;
}
#endif

#if 0
int Add(int a, int b){
	return a + b;
}
int main(){
	const int&& ra = 10;
	// ���ú�������ֵ������ֵ��һ����ʱ������Ϊ��ֵ
	int&& rRet = Add(10, 20);
	return 0;
}
#endif



#if 0
//�º�����lambda��ԨԴ
class Rate
{
public:
	Rate(double rate) : _rate(rate)
	{}
	double operator()(double money, int year)
	{
		return money * _rate * year;
	}
private:
	double _rate;
};


int main()
{
	//�º���
	Rate rt(2.5);  
	cout << rt(1000, 2) << endl;  //rt(1000,2) ==> rt.operator()(1000, 2);


	//lambda���ʽ
	double rate = 2.5;
	auto rt1 = [rate](int money, int year)->double {return money * year * rate; };
	cout << typeid(rt1).name() << endl;
	cout << rt1(1000, 2) << endl;

	return 0;
}

#endif

#if 1


#endif

#if 1


#endif
#if 1


#endif

#if 0
int main() {
	auto f1 = [] {cout << "Hello C++." << endl; };
	auto f2 = [] {cout << "Hello Linux." << endl; };
	//f1 = f2;  //error

	auto f3 = f2;  //right
	f3();

	void (*funcPtr)();
	funcPtr = f1;
	funcPtr();

	return 0;
}

#endif

#if 0
int z = 1000;
int main() {
	int a = 10;
	int b = 20;
	auto fun = [z, &a]()->void {
		cout << a << endl;
		a += 30;
		cout << a << endl;
	};
	fun();
	cout << a << endl;

	return 0;
}

#endif

#if 0
int main() {
	int a = 10;
	int b = 20;
	auto fun = [a]()mutable->void {
		cout << a << endl;
		a += 30;
		cout << a << endl;
	};
	fun();
	cout << a << endl;

	return 0;
}

#endif

#if 0
class Test
{
public:
	Test(int a = 0) : m_a(a)
	{}
public:
	void fun(int a)const
	{
		m_a = a;
	}
private:
	mutable int m_a;
};

void main()
{
	Test t(100);
	t.fun(1);
}

#endif








#if 0
struct Student
{
	char name[10];
	int  weight;
};

class stuCompareOfClass{
public:
	bool operator()(const Student& s1, const Student& s2)
	{
		return s1.weight < s2.weight;
		//return strcmp(s1.name, s2.name) >= 0;
	}
};

struct stuCompareOfStruct {
	bool operator()(const Student& s1, const Student& s2)
	{
		return s1.weight < s2.weight;
		//return strcmp(s1.name, s2.name) >= 0;
	}
};

int main()
{
	Student stu[] = { 
		{"��ͬѧ", 45}, {"��ͬѧ", 40},	
		{"��ͬѧ",60},{"��ͬѧ",55}
	};
	int n = sizeof(stu) / sizeof(stu[0]);
	sort(stu, stu+4, stuCompareOfClass());  //�º���
	//sort(stu, stu + 4, [](const Student& s1, const Student& s2)->bool {return s1.weight < s2.weight; });
	return 0;
}
#endif

#if 0
int main()
{
	int array[] = { 4,1,8,5,3,7,0,9,2,6 };
	int n = sizeof(array) / sizeof(array[0]);
	//sort(array, array + n);  //sort(array, array + n, less<int>());
	sort(array, array+n, greater<int>());
	for (int i = 0; i < n; ++i)
		cout << array[i] << " ";
	cout << endl;
	return 0;
}
#endif


#if 0
class Test
{
public:
	Test() = delete;
	Test(int data) : m_data(data)
	{}
	Test(const Test&) = delete;
private:
	int m_data;
};

void main()
{
	//Test t0;
	Test t(0);
	//Test t1 = t;
}
#endif


#if 0
int main() {
	forward_list<int> fl;
	fl.push_front(3);
	fl.push_front(2);
	fl.push_front(1);

	//�����Ҫβ�壺
	forward_list<int>::iterator itEnd;
	auto tmp = fl.begin();
	while (tmp != fl.end()) {
		itEnd = tmp;
		tmp++;
	}
	fl.insert_after(itEnd, 666);
	for (auto e : fl) {
		cout << e << " ";
	}
	cout << endl;

	//��ȡ��һ��Ԫ��front
	cout<<fl.front()<<endl;

	//��һ���ڵ��ǰ��
	forward_list<int>::iterator bbit = fl.before_begin();  
	bbit++;
	cout << *bbit << endl;

	//assign
	forward_list<int> fl2;
	fl2.push_front(6);
	fl2.push_front(5);
	fl2.push_front(4);
	forward_list<int>::iterator it = fl2.begin();
	forward_list<int>::iterator it2 = it;
	it2++;	it2++;
	fl.assign(it, it2);  //[iterator1,iterator2)
	for (auto e : fl) {
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
#endif


#if 0
int main()
{
	//ԭ��̬����������
	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };
	//ar[0];
	//*(ar+offset)
	int n = sizeof(ar) / sizeof(ar[0]);

	array<int, 10> br { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 10; ++i)
		cout << br[i] << " ";
	cout << endl;
	
	cout<<"pos : 1 is "<< br.at(1)<<endl;  //�����±��Ӧ��Ԫ��
	cout <<"first element: "<< br.front() << endl;  //��һ��Ԫ��
	cout <<"last element: "<< br.back() << endl;  //���һ��Ԫ��
	cout << "�ײ�����ĵ�ַ " << br.data() << endl;  //direct access to the underlying array
	int* arr = br.data();
	for (int i = 0; i < 10; ++i)
		cout << arr[i] << " ";
	cout << endl;

	
	cout << br.empty() << endl;
	cout << br.size() << endl;
	cout << br.max_size() << endl;



	array<int, 10> br1;
	br1.fill(5);  //��䷽��


	br1.swap(br);  //��������
	
	auto e = br.begin();
	while (e != br1.end())
		cout << *e++<<" ";
	cout << endl;

	for (int i = 0; i < br.size(); ++i)
		cout << br[i] << " ";
	cout << endl;
	return 0;
}
#endif

#if 0
void* GetMemory(size_t size)
{
	return malloc(size);
}
int main()
{
	// ���û�д��������Ƶ�����������
	cout << typeid(decltype(GetMemory)).name() << endl;

	// ����������б��Ƶ����Ǻ�������ֵ������,ע�⣺�˴�ֻ�����ݣ�����ִ�к���
	cout << typeid(decltype(GetMemory(0))).name() << endl;
	return 0;
}
#endif

#if 0
int main() {
	short a = 32670;
	short b = 32670;
	// ��decltype����a+b��ʵ�����ͣ���Ϊ����c������
	decltype(a + b) c;
	cout << typeid(c).name() << endl;
	return 0;
	return 0;
}

#endif

#if 0
int main() {
	auto a;
	cout << typeid(a).name() << endl;
	return 0;
}

#endif

#if 0
int main() {
	set<int> s = { 3,6,9,3,2,1,5,8 };
	//set<int>::iterator it = s.begin();
	//set<int>::reverse_iterator rit = s.rbegin();
	auto it = s.begin();
	auto rit = s.rbegin();
	cout << typeid(it).name() << endl;
	cout << typeid(rit).name() << endl;

	while (it != s.end())	
		cout << *it++ << " ";
	cout << endl;

	while (rit != s.rend())	
		cout << *rit++ << " ";
	cout << endl;
	return 0;
}
#endif




#if 0
int main() {
	short a = 32670;
	short b = 32670;

	short c = a + b;
	cout << c << endl;  //max = 32767
	cout << typeid(c).name() << endl;  //short

	auto x = a + b;
	cout << x << endl;  //65340
	cout << typeid(x).name() << endl;  //int
	return 0;
}
#endif


#if 0
template<class Type>
class SeqList
{
public:
	SeqList(size_t sz) : capacity(sz), size(0)
	{
		base = new Type[capacity];
	}
	SeqList(initializer_list<Type> list) : capacity(list.size()), size(0)
	{
		base = new Type[capacity];
		for (const auto& e : list)
			base[size++] = e;
	}
	~SeqList()
	{
		if (base != nullptr)
			delete[]base;
		base = nullptr;
		capacity = size = 0;
	}
private:
	Type* base;
	size_t capacity;
	size_t size;
};

void main()
{
	SeqList<int> sq{ 1,2,3,4,5,6,7,8,9,10 };
}
#endif

#if 0
template<class type>
class Point2D
{
public:
	Point2D() = delete;
	Point2D(initializer_list<type> list)
	{
		auto e = list.begin();
		_x = *e;
		++e;
		_y = *e;
	}
private:
	int _x;
	int _y;
};

class Point3D
{
public:
	Point3D() = delete;
	Point3D(initializer_list<int> list) {
		initializer_list<int>::iterator it = list.begin();
		_x = *it++;
		_y = *it++;
		_z = *it;
	}
private:
	int _x;
	int _y;
	int _z;
};

int main()
{
	Point2D<int> p{ 1,2 };
	Point3D p2{ 1, 2, 3 };
	return 0;
}
#endif

#if 0
class Point2D
{
public:
	Point2D(int x = 0, int y = 0) : _x(x), _y(y)
	{}
private:
	int _x;
	int _y;
};

class Point3D
{
public:
	Point3D(int x = 0, int y = 0, int z = 0) : _x(x), _y(y), _z(z)
	{}
private:
	int _x;
	int _y;
	int _z;
};

int main()
{
	Point2D p{ 1,2 };
	Point2D p1(1, 2);

	Point3D p2{ 1, 2, 3 };
	Point3D p3(1, 2, 3);
	return 0;
}
#endif