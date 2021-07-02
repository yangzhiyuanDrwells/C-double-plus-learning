#include <stdio.h>

void swap(int a[], int i, int j) {
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void bubbleSort(int array[],int size)
{
	//����forѭ����ʱ�临�Ӷ� 
	//  n-1,n-2,n-3,��,1    (n-1)*n/2 
	//F(n) = (n-1)*n/2 )  = 1/2n^2 - n/2
	//O(n^2)
	
	//�Ľ���  ���ж��Ƿ��Ѿ�����9 - 16�� 
	int index = 1;
	
	for(int i = 0;i < size;i++){
	if(array[i] > array[i+1])
	index--;
	}
	
	for(int i = 0;i < size;i++) //ѭ����size�� 
	{
		//
		if(index == 1)
		 	break;
		 	
		 	
		 //�����Ѿ������� 
		 int orderd = 1; 
		 
		 for(int j = 0;j <= size - 2 - i;j++)  //  for(int j = 0;j < size - 1 - i;j++)
		 if(array[j] > array[j+1]){
		 swap(array,j,j+1);
		 orderd = 0;
		 } 
		 if(orderd == 1)
		 	break;
	}
}


int main()
{
	int num;
	printf("������Ҫð����������ֵĸ�����\n");
	scanf("%d",&num);
	int array[num];
	int i = 0;
	while(i < num){	
		scanf("%d",&array[i]);
		i++;
	}
	bubbleSort(array,num);
	int size = num;     //sizeof(array)/sizeof(int); 
	
//��ӡð������������
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	
	return 0;
}

/*
1	2	3	4	5
0	1	2	3	4	size

1	2	3	4	
0	1	2	3	size



*/


