#include <iostream>

//1. const������Ե��÷�const��Ա������
//2. ��const������Ե���const��Ա������
//3. const��Ա�����ڿ��Ե��������ķ�const��Ա������
//4. ��const��Ա�����ڿ��Ե���������const��Ա������


class Test
{
public:
	Test(int data = 0)
	{
		m_data = data;
	}
	Test FunConst(const Test &t)const
	{
		//t.Fun(t);  //3.const��Ա�����ڲ����Ե��������ķ�const��Ա����
		return Test(m_data + t.m_data);
	}
	Test Fun(const Test& t)
	{
		t.FunConst(t);  //4.��const��Ա�����ڿ��Ե���������const��Ա����
		m_data = m_data * 2;
		return Test(m_data + t.m_data);
	}
private:
	int m_data;
};


int main()
{
	Test t(20);
	Test t1;
	const Test T2;
	//T2.Fun(t);  //1.const���󲻿��Ե��÷�const��Ա����  (�п��ܶ�����Ա�ķ���Ȩ�ޱ��)
	t1.FunConst(t);  //2.��const������Ե���const��Ա����

	return 0;
}