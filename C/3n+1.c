/*对任意大于1的自然数n, 若n为奇数则变为3n+1,否则变为n/2，最终n一定会变为1。求变化的次数*/
#include<stdio.h>
/*
int main(){
	int n, count=0;
	scanf("%d",&n);
	while(n>1){
		if(n%2==1)
			n = 3*n + 1;
		else
			n = n/2;
		count++;
	}
	printf("%d\n",count);

	return 0;
}
*/

int main(){
	int n, count=0;
	scanf("%d", &n);
	while(n>1){
		if(n%2==1){
			n = n + (n-1)/2 + 1;
			count +=2;
		}else{
			n = n/2;
			count ++;
		}
	}
	printf("%d\n",count);
	return 0;
}
