#include<iostream>
using namespace std;
int main()
{
	int *a = new int (4);  /* ʹ��new�������̬���õĿռ䣬��������������󲻻��Զ���
��ϵͳ�������Ҫ�Լ�ʹ��delete�黹�ڴ�ռ䡣*/
			       
	cout <<*a<<endl<<endl; //����һ��int��ָ�븳ֵ��a������ַ�е����ݸ�ֵΪ4
	delete a;              /*�ͷŵ���int�Ŀռ�  delete a;ֻ���ͷ�*a��
	�����ݣ������ı�ָ��p����p��ŵ���Ȼ������ռ�ʱ�ĵ�ַ�� */
					       
	int j,k,l;				       
	for(j=0;j<4;j++)
	cout <<*(a+j)<<endl;   //ֻ������һ���ڴ�ռ� 

	
	int *b = new int[4];   //����һ����СΪ100����������ռ䡣
	for(k = 0;k<4;k++)
	cin >>*(b+k); 
	
	for(l = 0;l<4;l++)       
	cout <<*(b+l)<<endl;
	delete []a;            //�ͷ�int����ռ�
	return 0;
}
