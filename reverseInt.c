#include<stdio.h>
#include<limits.h>
int reverse(int x){
	int rev=0,pop=0;
	while(x!=0){
		pop = x%10;
		if(rev > INT_MAX/10 ||(rev==INT_MAX/10 && pop>7))	return 0;
		if(rev < INT_MIN/10 ||(rev==INT_MIN/10 && pop<-8))	return 0;
		rev = rev*10 + pop;
		x /= 10;
	}
	return rev;
}

int main(){
	printf("%d\n",reverse(123));
	return 0;
}
