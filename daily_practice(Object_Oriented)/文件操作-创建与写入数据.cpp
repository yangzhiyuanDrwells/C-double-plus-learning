#include <stdio.h>


int main()
{
const char* filename = "D:\\hell.txt";
FILE* fp = fopen(filename,"wb");
if(fp ==NULL)
{
	printf("failed to open file!\n");
	return -1;
}

char buf[] = "hello world !";
fwrite(buf,1,13,fp);

int a = 0x12345678;
fwrite(&a,1,4,fp);

fclose(fp);

return 0;
}

//fopen���ļ�
/*
FILE *fopen(const char *filename,const char *mode);  mode: ʹ��"wb"(w��ʾwrite,b��ʾbinary)
����ֵ���ļ�ָ��-> FILE * 
ȫ·��  (1)c:\\abc.txt   (2)c:/0/abc.txt
ʾ����

const char* filename = "c:/0/abc.txt";
FILE* fp = fopen(filename,"wb");
if(fp ==NULL)
{
printf("failed to open file!\n");
return -1;
}

*/
//fclose�ر��ļ�
/*
int fclose(FILE* stream);
������ stream ����ǰ��fopen�ķ���ֵ
ʾ����

fopen(fp);

*/
//д������
/*
size_t fwrite(const void* buf,size_t size,size_t count,FILE* stream);
������
buf Ҫд�������
size ���Ǵ�1
count �������ݵ��ֽ���
stream ����ǰ��fopen�ķ���ֵ
����ֵ���ֽ���
*/





