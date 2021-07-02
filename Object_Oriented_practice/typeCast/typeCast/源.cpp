#include <iostream>
using namespace std;


#if 1
class A
{
public:
	virtual void f() {}
};
class B : public A
{};
void fun(A* pa)
{
	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);
	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}
int main()
{
	A a;
	B b;
	fun(&a);
	fun(&b);
	return 0;
}
#endif

#if 0
class A{
private:
	int a = 0;
};
class B{
private:
	int b = 0;
};

class C : public A, public B{
};

int main(){
	C c;
	printf("%p, %p, %p\n", &c, reinterpret_cast<B*>(&c), static_cast<B*>(&c));
	printf("%p\n", (B*)&c);  
	/*reinterpret_cast�ǵͲ�ε����½��ͣ�����ȫ
	ǿ������ת����static_cast���Զ�����������ת������ȷ��*/
	return 0;
}
#endif


#if 0
void main()
{
	int a = 0;
	char *str = "This is a string.";

	//a = static_cast<int>(str);
	a = reinterpret_cast<int>(str);  //����ȫ
}
#endif

#if 0
int main() {
	int a = 0;
	const char* str = "string";
	a = reinterpret_cast<int>(str);
	return 0;
}

#endif



#if 0

void Test()
{
	const int a = 2;
	int* p = const_cast<int*>(&a);
	*p = 3;
	cout << a << endl;
}

int main() {

	const int a = 10;
	//int* p = (int*)&a;  //��ʽ����ת��
	int* pa = const_cast<int*>(&a);  //const_castɾ������
	*pa = 100;
	cout << a << endl;
	cout << *pa << endl;


	volatile int b = 99;
	int* pb = const_cast<int*>(&b);
	*pb = 100;
	cout << b << endl;
	cout << *pb << endl;

	Test();
	return 0;
}
#endif

#if 0
int main() {
	double a = 9.9;
	int b = static_cast<int>(a);
	//int* p = static_cast<int*>(&a);


	return 0;
}
#endif