#include <iostream>
 using namespace std;
 //�������޸���������
 //�ڴ˴�������main����������Box��
 //ʹ�������Ҫ�� 
 class Box
 {

	float 	Length; 
	float   Breadth; 
	float   Height;
	int     Volume;
public:	
	void setLength(int j);
	void setBreadth(int j);
	void setHeight(int j);
	int getVolume();
	
};
    void Box::setLength(int j)
	{
		Length=j;
	}
	void Box::setBreadth(int j)
	{
		Breadth=j;
	}
	void Box::setHeight(int j)
	{
		Height=j;
	}
	int Box::getVolume()
	{
		return Length*Breadth*Height;
	}
 int main( )
 {
    Box Box1;                // ���� Box1������Ϊ Box
    Box Box2;                // ���� Box2������Ϊ Box
    double volume = 0.0;     // ���ڴ洢���
  
    // box 1 ����
    Box1.setLength(6.0); 
    Box1.setBreadth(7.0); 
    Box1.setHeight(5.0);
  
    // box 2 ����
    Box2.setLength(12.0); 
    Box2.setBreadth(13.0); 
    Box2.setHeight(10.0);
  
    // box 1 �����
    volume = Box1.getVolume();
    cout << "Box1 �������" << volume <<endl;
  
    // box 2 �����
    volume = Box2.getVolume();
    cout << "Box2 �������" << volume <<endl;
    return 0;
 }
