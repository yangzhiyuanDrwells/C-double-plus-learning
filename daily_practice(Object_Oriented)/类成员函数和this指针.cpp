#include<iostream>
using namespace std;
class Object
{
private:
	int x;
	int y;
public:
	void change()
	{
		this->x = 10;
		this->y = 20;
	}
	int Add()
	{
		return this->x + this->y;
	}
	void Test()
	{
		cout<<"x = "<<this->x<<",y = "<<this->y<<endl;
		cout<<this->Add()<<endl;   //thisָ�����ֱ�ӷ��ʱ����������Ա ����private��public������
		cout<<"this :"<<this<<endl;		   //���ڲ����ʷ���ʱ������private��public������
	}							   
};

int main()
{
	Object obj;  
	obj.change();
	obj.Test();
	cout<<obj.Add()<<endl;
	//��Test������ʱ���Ѿ��Ѷ���obj��ָ�봫������
	//�������ڲ�������ôִ�еģ�û��Ҫ��������Ĵ�һ��ָ�����

	cout<<"obj : "<<&obj<<endl;  //��ӡ��ַprintf("obj : %p",&obj);   %p = ��ַ

/*
	Object obj;
	Object *p = &obj;
	p->change();
	p->Test();
	cout<<obj.Add()<<endl;
*/
return 0;
}
