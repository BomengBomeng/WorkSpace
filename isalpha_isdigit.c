#include<stdio.h>

int isalphaNew(char ch){
	if(ch<='z'&&ch>='a' || ch<='Z'&&ch>='A')
		return 1;
	else
		return 0;
}
int isdigitNew(char ch){
	if(ch<='9' && ch>='0')
		return 1;
	else
		return 0;
}

int main(){
	for(char i='!'; i<='~'; i++){
		printf("%c\talpha:%d\tdigit:%d\n",i, isalphaNew(i), isdigitNew(i));
	}

	return 0;
}
