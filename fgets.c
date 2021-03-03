#include<stdio.h>

int getNumFromChar(FILE *fp){
	int num=0;
	char str[30];
	fgets(str,30,fp);
	puts(str);
	for(int i=0; i<30; i++){
		if('0'<=str[i]&&str[i]<='9')
			num = num*10 + str[i]-'0';
		else
			break;
	}
	return num;
}

int main(){
	printf("%d\n",getNumFromChar(stdin));
	return 0;
}
