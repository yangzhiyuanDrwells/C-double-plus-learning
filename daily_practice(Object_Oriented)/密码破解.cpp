#include <stdio.h>
#include <string.h>
int main (void) 
{
	char a[100];
	gets(a);
	for(int i=0;i<strlen(a);i++){
		if(a[i]<'Z'&&a[i]>='A'){
			a[i]+=33;
		}
		else if(a[i]=='Z'){
			a[i]='a';
		}
		else if(a[i]>='a'&&a[i]<='c'){
			a[i]='2';
		}
		else if(a[i]>='d'&&a[i]<='f'){
			a[i]='3';
		}
		else if(a[i]>='g'&&a[i]<='i'){
			a[i]='4';
		}
		else if(a[i]>='j'&&a[i]<='l'){
			a[i]='5';
		}
		else if(a[i]>='m'&&a[i]<='o'){
			a[i]='6';
		}
		else if(a[i]>='p'&&a[i]<='s'){
			a[i]='7';
		}
		else if(a[i]>='t'&&a[i]<='v'){
			a[i]='8';
		}
		else if(a[i]>='w'&&a[i]<='z'){
			a[i]='9';
		}
	}
	for(int i=0;i<strlen(a);i++){
		printf("%c",a[i]);
	}
} 
