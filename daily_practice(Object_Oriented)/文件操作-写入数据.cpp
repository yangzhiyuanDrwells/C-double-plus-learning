#include <stdio.h>
#include <string.h>
//#define bug
//����ṹ��
struct Student
{
	int id;        //ID
	char gender;   //�Ա�
	char name[16]; //����
};
int main()
{
//���ļ�
const char* filename = "D:\\hell2.txt";   // ����  "D:/hell2.txt"
FILE* fp = fopen(filename,"wb");
if(fp ==NULL)
{
	printf("failed to open file!\n");
	return -1;
}

int buf[4] = { 0xA001,0xB002,0xC003,0XD004};

#ifdef bug
fwrite(buf,1,sizeof(buf),fp); //����1�����ֽ�д��)
#endif

#ifndef bug
for(int i=0;i<4;i++)            //����2
{
	char text[16];
	sprintf(text,"%d,",buf[i]);   //�����ָ�ʽ����һ���ַ������ٽ��ַ���д���ļ�
 	fwrite(text,1,strlen(text),fp);
	printf("i = %d  strlen_of_buf[i]%d\n",i,strlen(text));
	printf("\n\n");
}
#endif

printf("%d\n",sizeof(buf));

//д�븡���� ����2��
double a  = 4/3.0;
char text[16];
sprintf(text,"%.13f",a);  //����ֻ�ܱ��浽С�����13λ��text[n]��n-1����
fwrite(text,1,strlen(text),fp);
printf("strlen_of_double_a %d\n",strlen(text));
printf("\n\n");

//д�븡���� ����1��
double b = 3 / 4.0;
fwrite(&b,1,sizeof(b),fp);

//д���ַ�����hello��
char buf_[] = "hello";
fwrite(buf,1,strlen(buf_),fp);

//�����ṹ��Ķ���
Student someone = {20150101,'M',"Noral"};

//�ṹ�����ݵ�д��

//(1)����д�뷨
#ifdef bug
fwrite(&someone,1,sizeof(someone),fp);
#endif

//(2)�����ֶηֿ�д
#ifndef bug
fwrite(&someone.id,    1,4,fp);
fwrite(&someone.gender,1,1,fp);
fwrite(&someone.name,  1,sizeof(someone.name),fp);
#endif

//�ر��ļ�
fclose(fp);

return 0;
}
/*
*******************
//fopen���ļ�
*******************

FILE *fopen(const char *filename,const char *mode);  
mode: ʹ��"wb"(w��ʾwrite ,b��ʾbinary) == ����д�� ÿ�δ��ļ������ԭ�����ݣ���ʹ��д�������ݣ�Ҳ�ᱻ����
mode: ʹ��"ab"(a��ʾappend,b��ʾbinary) == ׷��д�� ÿ�δ��ļ������ԭ�����ݣ�������׷����ĩβ
fopen����NULL����� <1>Ŀ¼�����ڰ� <2>���ڵ�ֻ����ʽ���ļ���"wb"��ʽ��
����ֵ���ļ�ָ��-> FILE * 
ȫ·��  (1)c:\\abc.txt  ��ע��ʹ�÷�б�ܵ�ʱ��  ��ת���ַ���\\���� (2)c:/0/abc.txt
·���ļ��� <1> ��׺��������д  eg: text.dat \ text.data \ text.mydata123   <2> ����û�к�׺��Ҳ����

ʾ����

const char* filename = "c:/0/abc.txt";
FILE* fp = fopen(filename,"wb");
if(fp ==NULL)
{
printf("failed to open file!\n");
return -1;
}

*/
/*
*******************
//fclose�ر��ļ�
*******************
/*
int fclose(FILE* stream);
������ stream ����ǰ��fopen�ķ���ֵ
ʾ��: fopen(fp);

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
/*

*******************
//д����������
*******************
*/
/*
��һ��int ���飬�ڴ洢�ļ�ʱ��һ����������ʽ
int buf[4] = { 0xA001,0xB002,0xC003,0XD004};

����1�����ֽ�д�룩��ֱ�Ӱ��ֽ�����
	fwrite(buf,1,sizeof(buf),fp);
	(����VS���ڴ洰������⣩

����2����ʽ��Ϊ�ַ���д��
for(int i=0;i<4;i++)
{
	char text[16];
	sprintf(text,"%d,",buf[i]);  //��ʽ��Ϊ�ַ���д��,ÿ�������м��һ������
	fwrite(test,1,strlen(test),fp);
}
sprintf-> n. �Ѹ�ʽ����д�ɴ�������ָ�

*******************
���ڸ�������float,double),Ҳ����ʹ��������д��
*******************
��1��
double a = 3 / 4.0;
fwrite(&a,1,sizeof(a),fp);

��2������2���׶�ʧ����
double a  = 4/3.0;
char text[16];
sprintf(text,"%.13f",a); 
fwrite(text,1,strlen(text),fp);

*******************
д���ַ���
*******************
��1����ʵ�ʳ���д��
char buf[] = "hello";
fwrite(buf,1,strlen(buf),fp);

(2) ���̶�����д��
char buf[16] = "hello";
fwrite(buf,1,16,fp);

*******************
�ṹ�����ݵ�д��
*******************

(1)����д�뷨
struct Student
{
	int id;        //ID
	char gender;   //�Ա�
	char name[16]; //����
}
Student someone = {20150101,'M',"Noral"};

fwrite(&someone,1,sizeof(someone),fp);

��2�������ֶηֿ�д
struct Student
{
	int id;        //ID
	char gender;   //�Ա�
	char name[16]; //����
}

Student someone = {20150101,'M',"Noral"};

fwrite(&someone.id,    1,4,fp);
fwrite(&someone.gender,1,1,fp);
fwrite(&someone.name,  1,sizeof(someone.name),fp);

*/




