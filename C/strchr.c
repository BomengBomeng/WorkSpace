#include<stdio.h>

int strchrNew(char *str, char ch){
	char *p = str;
	while(*p!='\0'){
		if(*p==ch)
			break;
		p++;
	}
	if(*p==ch)
		return p-str;
	else
		return -1;
}

int main(){
	char str[30];
	char ch = getchar();
	fgets(str,30,stdin);
	printf("%d\n",strchrNew(str,ch));
	return 0;
}
