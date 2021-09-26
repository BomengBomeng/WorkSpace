/*求输入的若干个整数的乘积末三位，要求忽略输入的字符*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXN 100

char str[MAXN];

int main(){
	int n=0,num=0,product=1;
	char ch;
	while(EOF!=(ch=getchar())){
		str[n++]=ch;
	}
	for(int i=0; i<n; i++){
		if(isdigit(str[i])){
			num = num*10 + str[i]-'0';
		}
		else{
			if(num!=0){
				product = (product*(num%1000))%1000;
			}
			num=0;
		}
	}


	printf("%03d\n",product);
	return 0;
}

