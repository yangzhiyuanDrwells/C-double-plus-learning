#if 0

#include <iostream>
using namespace std;
int main() {
	try {
		int* p = new int[536870911];  //array_max_bit: 2147483647bit
	}catch(bad_alloc &e){
		cout << e.what() << endl;
		return 0;
	}
	cout << "alloc successed" << endl;
	return 0;
}

#endif


#if 0
#include <iostream>
using namespace std;

#define DefaultArraySize 10

template<typename elemType>
class Array{
private:
	int  size;
	elemType* ia;
public:
	explicit Array(int sz = DefaultArraySize)	{
		size = sz;
		ia = new elemType[size];
	}
	~Array(){
		delete[] ia;
	}
	elemType& operator[](int ix) const
	{
		if (ix < 0 || ix >= size)		{
			string eObj = "out_of_range error in Array<elemType >::operator[]()";
			throw out_of_range(eObj);
			//throw range_error(eObj);
			//throw bad_alloc(eObj);
		}
		return  ia[ix];
	}
};

int main()
{
	//int br[10];   br[12];
	Array<int> ar;
	for (int i = 1; i <= 10; ++i)
		ar[i - 1] = i;

	try	{
		for (int i = 0; i <= 10; ++i)
			cout << ar[i] << " ";
		cout << endl;
	}catch (const out_of_range & e)	{
		cout << endl;
		cout << e.what() << endl;
		return 0;
	}
}
#endif


#if 0
#include <iostream>
using namespace std;

double Division(int a, int b)
{
	// ��b == 0ʱ�׳��쳣
	if (b == 0)	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
void Func()
{
	// ������Կ������������0�����׳��쳣�����������arrayû�еõ��ͷš�
	// �������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦�����ﲶ������
	// �����׳�ȥ��
	int* array = new int[10];
	try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)	{
		cout << "delete []" << array << endl;
		delete[] array;
		throw;
	}
	// ...
	cout << "delete []" << array << endl;
	delete[] array;
}
int main()
{
	try	{
		Func();
	}catch (const char* errmsg)	{
		cout << errmsg << endl;
	}
	return 0;
}
#endif


#if 0
#include <iostream>
using namespace std;

//ջ���쳣����
template<typename T>
class pushOnFull
{
private:
	T _value;
public:
	pushOnFull(T i)	{
		_value = i;
	}
	T value()const	{
		return _value;
	}
	void print()	{
		cerr << "ջ����" << value() << "δѹ��ջ" << endl;
	}
};

//ջ���쳣����
template<typename T>
class popOnEmpty
{
public:
	void print()	{
		cerr << "ջ�ѿգ��޷���ջ" << endl;
	}
};

template<typename T>
class Stack
{
private:
	int top;                                    //ջ��ָ�루�±꣩
	T* elements;                               //��̬��������ֵ
	int maxSize;                               //ջ������ɵ�Ԫ�ظ���
public:
	Stack(int default_size = 20)	{
		maxSize = default_size;
		elements = new T[maxSize];
		top = -1;
	}
	~Stack()	{
		delete[] elements;
	}
	////////////////////////////////////////////////////////////////
	void Push(const T& data) throw(pushOnFull<T>)	{
		if (IsFull())
			throw pushOnFull<T>(data);
		elements[++top] = data;
	}
	T Pop() throw(popOnEmpty<T>)	{
		if (IsEmpty())
			throw popOnEmpty<T>();

		T data = elements[top];
		top--;
		return data;
	}
	/////////////////////////////////////////////////////////////////
	bool IsEmpty() const	{
		return top == -1;
	}
	bool IsFull() const	{
		return top == maxSize - 1;
	}
	void PrintStack()	{
		for (int i = top; i >= 0; --i)
			cout << elements[i] << " ";
		cout << endl;
	}
};


int main()
{
	Stack<int> st(10);

	try	{
		for (int i = 1; i <= 10; ++i)
		{
			st.Push(i);
		}
	}	catch (pushOnFull<int>& e)
	{
		e.print();
		return 0;
	}
	st.PrintStack();

	try	{
		for (int i = 0; i <= 10; ++i)
			st.Pop();
	}	catch (popOnEmpty<int>& e)
	{
		e.print();
		return 0;
	}
	cout << "Main End." << endl;
	return 0;
}

#endif



















#if 0
//C++11 shared_ptr
#include <iostream>
#include <memory>  //new 
using namespace std;
int main()
{
	int* p = new int(10);
	int* q = new int(20);

	shared_ptr<int> sp1(p);
	cout << *sp1 << endl;
	cout << "use_count = " << sp1.use_count() << endl;

	{
		shared_ptr<int> sp2 = sp1;
		cout << "use_count = " << sp1.use_count() << endl;
	}
	cout << "use_count = " << sp1.use_count() << endl;


	sp1.reset(q);  //�ض������õ���Դ
	cout << *sp1 << endl;
	return 0;
}
#endif

#if 0
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
// 1.��ʾ���ü����̰߳�ȫ���⣬�Ͱ�AddRefCount��SubRefCount�е���ȥ��
// 2.��ʾ���ܲ������̰߳�ȫ���⣬��Ϊ�̰߳�ȫ������ż�������⣬main������n�Ĵ�һЩ���ʾͱ���ˣ������׳����ˡ�
// 3.�����������ʹ��SharedPtr��ʾ����Ϊ�˷�����ʾ���ü������̰߳�ȫ���⣬�������е�SharedPtr����shared_ptr���в��ԣ�������֤���shared_ptr�����ֽ�����һ���ġ�
template <class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)
		: _ptr(ptr)
		, _pRefCount(new int(1))
		, _pMutex(new mutex)
	{}
	~SharedPtr() { Release(); }
	SharedPtr(const SharedPtr<T>& sp)
		: _ptr(sp._ptr)
		, _pRefCount(sp._pRefCount)
		, _pMutex(sp._pMutex)
	{
		AddRefCount();
	}
	// sp1 = sp2
	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		//if (this != &sp)
		if (_ptr != sp._ptr)
		{
			// �ͷŹ���ľ���Դ
			Release();
			// ��������¶������Դ�����������ü���
			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pMutex = sp._pMutex;
			AddRefCount();
		}
		return *this;
	}
	T& operator*() { return *_ptr; }
	T* operator->() { return _ptr; }
	int UseCount() { return *_pRefCount; }
	T* Get() { return _ptr; }
	void AddRefCount()
	{
		// ��������ʹ�ü�1��ԭ�Ӳ���
		_pMutex->lock();
		++(*_pRefCount);
		_pMutex->unlock();
	}
private:
	void Release()
	{
		bool deleteflag = false;
		// ���ü�����1���������0�����ͷ���Դ
		_pMutex->lock();
		if (--(*_pRefCount) == 0)
		{
			delete _ptr;
			delete _pRefCount;
			deleteflag = true;
		}
		_pMutex->unlock();
		if (deleteflag == true)
			delete _pMutex;
	}
private:
	int* _pRefCount; // ���ü���
	T* _ptr; // ָ�������Դ��ָ��
	mutex* _pMutex; // ������
};

class Date
{
public:
	Date(int year = 0, int month = 0, int day = 0)
		:_year(year), _month(month), _day(day)
	{ cout << "Date()" << endl; }
	~Date() { cout << "~Date()" << endl; }
	int _year;
	int _month;
	int _day;
};

void SharePtrFunc(SharedPtr<Date>& sp, size_t n)
{
	cout << sp.Get() << endl;
	for (size_t i = 0; i < n; ++i)
	{
		// ��������ָ�뿽����++����������ָ��������--�������������̰߳�ȫ�ġ�
		SharedPtr<Date> copy(sp);
		// ��������ָ����ʹ������Դ�������̰߳�ȫ�ġ��������ǿ�����Щֵ�����߳�++��2n�Σ��������տ����Ľ������һ���Ǽ���2n
		copy->_year++;
		copy->_month++;
		copy->_day++;
	}
}
int main()
{
	SharedPtr<Date> p(new Date);
	cout << p.Get() << endl;
	const size_t n = 999999;
	thread t1(SharePtrFunc, ref(p), n);
	thread t2(SharePtrFunc, ref(p), n);
	t1.join();
	t2.join();
	cout << p->_year << endl;
	cout << p->_month << endl;
	cout << p->_day << endl;
	return 0;
}
#endif


#if 0
//ѭ������
#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode
{
public:
	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
	T data;
	shared_ptr<ListNode<T>> m_prev;   //ListNode *m_prev;
	shared_ptr<ListNode<T>> m_next;   //ListNode *m_next;
};

int main()
{
	shared_ptr<ListNode<int>> node1(new ListNode<int>);
	shared_ptr<ListNode<int>> node2(new ListNode<int>);
	cout << "use_count 1 = " << node1.use_count() << endl;
	cout << "use_count 2 = " << node2.use_count() << endl;

	node1->m_next = node2;
	node2->m_prev = node1;

	cout << "use_count 1 = " << node1.use_count() << endl;  //2
	cout << "use_count 2 = " << node2.use_count() << endl;  //2
	return 0;
}

#endif



#if 0
//ѭ������:����취
#include <iostream>
#include <memory>
using namespace std;

template<class T>
struct ListNode
{
public:
	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
	T data;
	weak_ptr<ListNode<T>> m_prev;   //ListNode *m_prev;  //��ָ�� * ->
	weak_ptr<ListNode<T>> m_next;   //ListNode *m_next;
};

int main()
{
	shared_ptr<ListNode<int>> node1(new ListNode<int>);
	shared_ptr<ListNode<int>> node2(new ListNode<int>);
	cout << "use_count 1 = " << node1.use_count() << endl;
	cout << "use_count 2 = " << node2.use_count() << endl;

	node1->m_next = node2;
	node2->m_prev = node1;

	cout << "use_count 1 = " << node1.use_count() << endl;  //2
	cout << "use_count 2 = " << node2.use_count() << endl;  //2
	return 0;
}

#endif




#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//��������ɾ����
template<class T>
struct freeMalloc{
	void operator()(T* ptr)	{
		cout << "free type ptr : " << ptr << endl;
		free(ptr);
	}
};

//�ļ�ָ��ɾ����
struct freeFile {
	void operator()(FILE* fp) {
		cout << "free file ptr : " << fp << endl;
		fclose(fp);
	}
};

template<typename U>
auto freeMal = [](U* p)->void {free(p); };

auto freeFil = [](FILE* fp)->void {fclose(fp); };

void freeFi(FILE* fp) {
	fclose(fp);
}
int main()
{
	//�������new�ģ�����malloc�������ļ�ָ����׽���
	int *p = (int *)malloc(sizeof(int));

#if 0
	shared_ptr<int> is(p, freeMalloc<int>());  //�º���
#else
	//shared_ptr<int> is(p, [](int* p)->void {free(p); } );  //lambda
	shared_ptr<int> is(p, freeMal<int>);  //lambda
#endif


	FILE* fp = fopen("test.txt", "w");
#if 0
	//shared_ptr<FILE> fs(fp, freeFile());  //�º���
#else
	//shared_ptr<FILE> fs(fp, [](FILE* fp)->void {fclose(fp); } );  //lambda
	shared_ptr<FILE> fs(fp, freeFil );  //lambda
	//shared_ptr<FILE> fs(fp, freeFi);  //������ַ
#endif

	return 0;
}

#endif

















#if 1

#endif

#if 1

#endif

#if 1

#endif

#if 1

#endif

#if 1

#endif

#if 1

#endif

#if 1

#endif
