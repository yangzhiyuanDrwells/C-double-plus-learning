#include <stdio.h>
#include <string.h>
#include <stdlib.h>  //malloc����
//#define bug;

//����ṹ��
	struct Car
	{
		char maker[32]; //������
		int price;      //�۸�
	};
	struct Citizen
	{
		char name[32]; //����
		int  deposite; //���
		Car* car;	   //NULLʱ��ʾû��
	};
//�洢���� 
int save()
{
	const char* filename = "D:\\data_storage_format.txt";
	FILE* fp = fopen(filename,"wb");
	if(fp == NULL)
	{
		printf("failed to open file!\n");
		return -1;
	}
/*
	int a = 12345;
	int b = 6789;

	char buf[128];
	sprintf(buf,"%d,%d",a,b); //int��������֮���Զ��Ÿ��� 
	fwrite(buf,1,strlen(buf),fp);
*/

//�������͵ı����Ĵ洢
	int a = 0x12345678;
	int b = 0x0A0A0A0A;
	fwrite(&a,1,4,fp);
	fwrite(&b,1,4,fp);

//��֪���ȵ�����Ĵ洢
	float arr[4] = {1.1f,1.2f,1.3f,1.4f};
	fwrite(arr,1,4*4,fp);
/*
//δ֪���������д��
float arr[256];
arr = getchar();               //error
*/

//�ַ�����Ĵ洢
	char text[32] = "shaofa,sdjvjfdvbjrhljh";
	fwrite(text,1,32,fp);
Car* car = (Car*) malloc(sizeof(Car));
	strcpy(car->maker, "Chevrolet");
	car->price = 10; 

//ָ��Ĵ洢
	Citizen who = {"shaofa",100};
	who.car = car;
	
	fwrite(who.name,1,32,fp);
	fwrite(&who.deposite,1,4,fp);
	if(who.car != NULL)
	{
		fwrite("Y",1,1,fp); //����һ���ֽڡ�Y��
		fwrite(who.car->maker,1,32,fp);
		fwrite(&who.car->price,1,4,fp); 
	}
	else
	{
		fwrite("N",1,1,fp); //����һ���ֽڡ�N��
	}
	
	fclose(fp);
	return 0;
}
//��ȡ���� 
int load()
{
	const char* filename = "D:\\data_storage_format.txt";
	FILE* fp = fopen(filename ,"rb");
	if(fp == NULL)
{
	printf("failed to open file!\n");
	return -1;
}

//����һ��128�ֽڵĻ�����
	//char buf[128];
	//int n = fread(buf,1,128,fp);
	//printf("n = %d",n);

/*
//˳���ȡ
	char buf[4];
	while(! feof (fp)) 
	{
		int n = fread (buf ,1,4,fp);
		if(n > 0 )
		{
			printf("Read %d bytes \n",n);
		}
	}
	//�۲췵��ֵn��ֵ ʵ�ʶ�ȡ�����ֽڸ��� ������n = 21
	//�۲�buf�������  
*/

//�������͵ı����Ķ�ȡ
	int a,b;
	fread(&a,1,4,fp);
	fread(&b,1,4,fp);
	printf("int read: a = %d,b = %d \n",a,b);

//δ֪��������Ķ�ȡ
#ifdef bug
	//����ȡ��δ֪���ȵ�float�������arr����
	float arr[256];
	int count = 0;

	while(! feof(fp))
{
	float a;
	if(fread(&a,1,4,fp) <= 0)
	{
		break;
	}
	printf("string_float read: %.2f \n",a);

	arr[count] = a;//����ȡ��float�������arr����
	count ++;
}
//��ӡ����arr�����float����
	printf("print_new_float_arr[count]\n");

	for(int j = 0;j<count;j++)
	{
		printf("j = %d,new_float_arr[j] = %.2f\n",j,arr[j]);
	}
#endif

//��֪��������Ķ�ȡ
#ifndef bug
float acc[4];
fread(acc,1,4*4,fp);
//��ӡ����acc�����float����
	printf("print_new_float_acc[4]\n");
	for(int j = 0;j<4;j++)
	{
		printf("j = %d,new_float_acc[j] = %.2f\n",j,acc[j]);
	}
#endif


//�ַ�����Ķ�ȡ
	char abc[32];
	//fread (abc,1,32,fp);
	int  n = fread(abc,1,32,fp);
	printf("%d",n);
//��ӡ����abc������ַ�����
	printf("print_new_character_abc[i]\n");

	printf("new_character_abc[j]= %s \n",abc);

	for(int j = 0;j<n;j++)
	{
		printf("j = %2d,new_character_acc[j]= %c\n",j,abc[j]);
	}

//ָ��Ķ�ȡ
Citizen who;
	fread(who.name,1,32,fp);	
	fread(&who.deposite,1,4,fp);
	
	char has = 'N';
	fread(&has,1,1,fp);
	if(has == 'Y')
	{
		Car* car = (Car*) malloc(sizeof(Car));
		fread(car->maker,1,32,fp);
		fread(&car->price,1,4,fp);
		who.car = car;
//		printf("car.maker = %s, car.prince = %d" ,car->maker,car->price);
	}
	else
	{
		who.car = NULL;
	}
/*
printf("who.car.maker = , who.car.prince = , 
who.name = %c,who.deposite = %d",
who.car->maker,who->car->price,who.name,who.deposite);
*/
	fclose(fp);
	return 0;
}
int main()
{
	save();
	load();
	return 0;
}
/*
���ݴ洢�Ļ���ԭ��
�ܹ�д�룬Ҳ�ܹ���������ԭ
eg:
ʧ�ܵĴ洢 ����int������ �� 12345��6790

ʧ�ܣ�
char buf[128];
sprintf("%d%d",a,b);
fwrite(buf,1,strlen(buf),fp);

���У�
char buf[128];
sprintf("%d,%d",a,b); //int��������֮���Զ��Ÿ���

������Զ��Ÿ��������޷������ݽ��н��������ݰ״��ˣ�

���ݴ洢�ĸ�ʽ�ǲ��޵ģ�ֻҪ��������
����д�룬�ܶ�������ԭ����ԭ�����ַ���������

************************
��򵥵ķ��������ֽڴ洢
************************
char / short / int : ռ1��2��4���ֽ�
float / double : 4��8���ֽ�
���飺
�ַ���;
ָ�룺��������

��1���������͵ı���
	char / short / int / float / double�ͱ����Ĵ洢
	ֻ��Ҫ֪�������ĵ�ַ�ʹ�С

	//д��
	int a = 0x12345678;
	int b = 0x0A0A0A0A;
	fwrite(&a,1,4,fp);
	fwrite(&b,1,4,fp);

	//��ȡ
	int a,b;
	fread(&a,1,4,fp);
	fread(&b,1,4,fp);

��2������Ĵ洢
	//д��
	��ַ��������
	�ֽ������ֹ�����

	<2>��֪���������д��
	float arr[4];
	fwrite(arr,1,4*4,fp);

	<1>δ֪���������д��
	float arr[256];
	arr = getchar();               //error


	//��ȡ
	<1>δ֪��������Ķ�ȡ
	���ڲ�֪��һ���洢�˶��ٸ�float,��Ҫѭ����ȡ
	while(! feof(fp))
	{
		float a;
		if(fread(&a,1,4,fp) <= 0)
		{
			break;
		}
	}
	<2>��֪��������Ķ�ȡ

	float acc[4];
	fwrite(acc,1,4*4,fp);


��3���ַ�����Ĵ洢��һ�ּ򵥴�ȡ��ʽ��
	������ʽ��ȡ��������Ч�����Ƕ��٣�ͳһ�洢32���ֽ�

	char text[32];
	fwrite(text,1,32,fp);
	fread (text,1,32,fp);

	�ַ�����Ķ�ȡ
	char abc[32];
	fread (acc,1,32,fp);
��4���ṹ��Ĵ洢
	<1>ֱ�Ӵ�ȡ�����ṹ��
	struct Student
	{
	int id;
	char name[16];
	int scores[3];
	};
	Student s = {201501,"shaofa",{90,90, 90} };
	//д��
	fwrite(&s,1,sizeof(s),fp);
	//����
	fread (&s,1,sizeof(s),fp);

	<2>��ÿ����Ա�������δ洢
	struct Student
	{
	int id;
	char name[16];
	int scores[3];
	};
	Student s = {201501,"shaofa",{90,90, 90} };

	//д��
	fwrite(&s.id,    1,sizeof(s.id),fp);
	fwrite(&s.name,  1,sizeof(s.name),fp);
	fwrite(&s.scores,1,sizeof(s.scores),fp);

	//����
	fread (&s.id,    1,sizeof(s.id),    fp);
	fread (&s.name,  1,sizeof(s.name),  fp);
	fread (&s.scores,1,sizeof(s.scores),fp);

(5)ָ��Ĵ洢
ָ��Ҫô���洢��Ҫô�洢��ָ��Ķ��������
��ָ�뱾��û�б�Ҫ�洢����ֻ��һ����ַ��
struct Car
{
	char maker[32]; //������
	int price;      //�۸�
}��
struct Citizen
{
	char name[32]; //����
	int  deposite; //���
	Car& car;	   //NULLʱ��ʾû��
}

Car* car = (Car*) malloc(sizeof(Car));
strcpy(car->maker, "Chevrolet");

car->price = 10; 

Citizen who = {"shaofa",100};
who.car = car;



*/












/*

(1)���ļ� ��fopen �õ�FILE*
const char* filename = "D:\\ file 'rb'";
FILE* fp = fopen(filename ,"rb");
if(fp == NULL)
{
	printf("failed to open file!\n");
	return -1;
}
ģʽΪ"rb"  (read, binary)  //������"rb"����Ȼ�����
(2)��ȡ���� ��fread ...
(3)�ر��ļ� ��fclose

��ȡ���ݺ���
size_t fread(void *buf size,size_t nelem,FILE* stream);
����ֵ �� ʵ�ʶ�ȡ�����ֽڸ���

//˳���ȡ
����ļ��������޷�һ�ζ��꣬���Բ���˳����룬
ÿ�ζ�ȡһ�����ȣ�ֱ����ȡ��
char buf[4]
while(! feof (fp))
{
	int n = fread (buf ,1,4,fp);
	if(n > 0 )
	{
		printf("Read %d bytes \n",n);
	}
}
ע��ʹ��feof���������ļ��Ƿ��Ѿ�����ĩβ��EOF��End of File��
*/