/*字符串循环移动，求最大相同连续字串*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str[2000];
int n;


int main(){
	int len;
	char ch;
	while(scanf("%s %d",str,&n)==2){
		len = strlen(str);
		if(n>=len){
			n %= len; 
		}
		for(int i=0; i<n/2; i++){
			ch = str[i];
			str[i] = str[n-i-1];
			str[n-i-1] = ch;	
		}
		for(int j=0; j<(len-n)/2; j++){
			ch = str[j+n];
			str[j+n] = str[len-j-1];
			str[len-j-1] = ch;
		}
		for(int k=0; k<len/2; k++){
			ch = str[k];
			str[k] = str[len-k-1];
			str[len-k-1] = ch;
		}
		puts(str);
	}
	return 0;
}
