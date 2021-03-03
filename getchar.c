#include<stdio.h>

int getNumFromChar(){
	char ch;
	int num=0;
	ch=getchar();
	while('0'<=ch && ch<='9'){
		num = num*10 + (ch-'0');
		ch = getchar();
	}
	return num;
}

int main(){
	printf("%d\n",getNumFromChar());
	return 0;
}
