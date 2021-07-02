#include <iostream>
#include <string.h>
//#define bug
using namespace std;

int save()
{
	const char* filename = "D:\\data_storage_format.txt";
	FILE* fp = fopen(filename,"wb");
	if(fp == NULL)
	{
		printf("failed to open file!\n");
		return -1;
	}
#ifdef bug
//���д洢(sprintf)
	char ip[] = "192.168.1.100";
	int port = 8080;

	char line[256];
	sprintf(line,"ip = %s\n",ip);
	fwrite(line,1,strlen(line),fp);

	sprintf(line,"port = %d\n",port);
	fwrite(line,1,strlen(line),fp);
#endif
//���д洢(fprintf)
#ifndef bug
	char ip[] = "192.168.1.100";
	int port = 8081;

	fprintf(fp,"ip = %s\n",ip);
	fprintf(fp,"port = %d\n",port);

#endif
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

//�������ݵĶ�ȡ
	char buf[512];
	while(! feof(fp))
	{
		char* line = fgets(buf,512,fp);
		if(line)
		{
			printf("got: %s",line);
		}
	}

	fclose(fp);
	return 0;
}
int main()
{
	char line[] = "id  = 123,name = shaofa,hometown = anhui";

	int id;
	char name[32];
	char hometown[32];
	sscanf(line,"id = %d,name = %s,hometown = &s", 
		&id,name,hometown);     //���н�����һ����sscanf���޷�ʤ�ε�
							    //sscanfֻ�ʺ���ȡ���֣�������ȡ�ַ���
	save();                     
	load(); 
	return 0;
}
/*


���ı���ʽ�洢

���������Ƚ�Сʱ,�������ı���ʽ�洢�����ǰ���������
����ʽ�����ַ������洢
ͨ�������ļ������ı���ʽ�洢��,����*xml,cfg*.ini
 
����,��xm1�ļ��д洢ip�Ͷ˿ں�
<?xml version=1.0" encoding=gb2312 ?>
��Root>
	��ip>192.168.10.60��/ip��
	��port��8080��/port��
</root>


���д洢(sprintf)
��ÿ����Ԫ�����ݸ�ʽ��Ϊһ�У�ĩβ����/n��,д���ļ�

	���磬����ip��port
	char ip[] = "192.168.1.100";
	int port = 8080;

	char line[256];
	sprintf(line,"ip = %s\n,ip");
	fwrite(line,1,strlen(line),fp);

	sprintf(line,"port = %d\n",port);
	fwrite(line,1,strlen(line),fp);


���д洢(fprintf)
Ҳ����ֱ��ʹ��fprintf����
	char ip[] = "192.168.1.100";
	int port = 8081;

	fprintf(fp,"ip = %s\n",ip);
	fprintf(fp,"port = %d\n,port");

	fprintf����һ���������ļ�ָ�룬����Ĳ�����printf
	ֱ�ӽ����ݸ�ʽ�����ַ�����д���ļ�
	ȱ�㣺����ʱ���Ӷ���Խϸ�
	���ڲ�֪��ÿ�г����Ƕ೤��������fread��ȡʱ����Ҫ����Ƿ�
	�Ѿ�����\n����ָ������е㸴�Ӱ���

	�Ƽ�ʹ��fgets����,��������Ѿ���������߼�����װ���ˡ�
	fgets�ڲ����飬�������ַ�\nʱ��ֹͣ��ȡ������ʵ��
	��ȡ���ֽڳ��ȡ�
*/