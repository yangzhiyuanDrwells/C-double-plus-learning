#include <stdio.h>
struct Student
{
	int id;        //ID
	char gender;   //�Ա�
	char name[16]; //����
};
//�洢����
int save()
{
	const char* filename = "D:\\file 'rb'.txt";
	FILE* fp = fopen(filename,"wb");
	if(fp == NULL)
	{
		printf("failed to open file!\n");
		return -1;
	}

	Student someone = {20150101,'M',"Noral"};
	fwrite(&someone.id,    1,4,fp);
	fwrite(&someone.gender,1,1,fp);
	fwrite(&someone.name,  1,sizeof(someone.name),fp);
	fclose(fp);
	return 0;
}
//��ȡ���� 
int load()
{
	const char* filename = "D:\\file 'rb'.txt";
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

	fclose(fp);
	return 0;
}
int main()
{
	//save();
	load();
	return 0;
}
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
