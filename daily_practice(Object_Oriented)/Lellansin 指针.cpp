#include <stdio.h>

void swap(int *x,int *y)
{
	int temp;
	
	temp=*x; /* �������л�ֵ��任��   */                        
	*x=*y;   /*��ָ�����i��j��ֵ	   */	
	*y=temp; /*�����и�ֵ*x=45;*y=13 Ҳ����ʵ����ͬ�Ĺ���  */
}
int main()
{
	int i=13,j=45;
	swap(&i,&j);
	printf("i=%d,j=%d",i,j);
}

