#include<stdio.h>

int fgetsNew(char *str, int n, FILE *fp){
	char ch;
	int count =0;
	ch = getchar();
	while(ch!='\n'){
		if(count==n)
			break;
		count++;
		*str = ch;
		str++;
		ch = getchar();
	}
	*str='\0';
	return count;
}
int main(){
	char str[60];
	printf("%d\n",fgetsNew(str,20,stdin));
	puts(str);
	return 0;
}
