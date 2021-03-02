#include<stdio.h>
#include<malloc.h>
char *connect(char *s1, char *s2){
	int len1=0, len2=0;
	char *p1=s1, *p2=s2, *r, *result;
	while(*p1!='\0'){
		len1++;
		p1++;
	}
	while(*p2!='\0'){
		len2++;
		p2++;
	}
	result = (char*)malloc(len1+len2);
	p1=s1;  p2=s2; r = result;
	while(*p1!='\0')
		*(r++) = *(p1++);
	while(*p2!='\0')
		*(r++) = *(p2++);
	*r = '\0';
	return result;
}
int main(){
	char s1[] = "abcde";
	char s2[] = "fghijk";
	char *result = connect(s1,s2);
	puts(result);
	return 0;
}
