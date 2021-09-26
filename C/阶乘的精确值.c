#include<stdio.h>
#include<string.h>
#define maxn 6000
char f[maxn];

int main(){
	int n;
	scanf("%d",&n);
	memset(f,0,sizeof(f));	//inital
	f[0]=1;
	int c, s;
	for(int i=2; i<=n; i++){
		c=0;
		for(int j=0; j<maxn; j++){
			s = f[j]*i + c;
			f[j] = s%10;
			c = s/10;
		}
	}
	int j;
	for(j=maxn-1; j>=0; j--) //略去前导 0
		if(f[j])
			break;
	printf("size: %d\n",j);
	for(;j>=0; j--)
		printf("%d",f[j]);
	printf("\n");
	return 0;
}
